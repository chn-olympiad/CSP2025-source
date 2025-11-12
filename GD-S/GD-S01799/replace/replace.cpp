#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&-x)
#define pii pair<int,int>
#define N 200010
int n,q;
namespace subt1{
	int ln,cnt[N];
	multimap<string,string> mp;
	pair<string,string> pr;
	pair<string,string> num[N];
	void solve(){
		for(int i = 1;i <= n;++i){
			cin >> pr.first >> pr.second;
			num[i] = pr;
		}sort(num+1,num+n+1);
		for(int i = 1;i <= n;++i){
			if(num[i] != num[ln])num[++ln] = num[i],cnt[ln] = 1;
			else ++cnt[ln];
		}
		while(q--){
			string t1,t2;cin >> t1 >> t2;
			int fa = 0,ga = 0;ll ans = 0;
			for(;fa < min(t1.size(),t2.size());++fa)if(t1[fa] != t2[fa])break;
			for(;ga < min(t1.size(),t2.size());++ga)if(t1[t1.size()-ga-1] != t2[t2.size()-ga-1])break;
			int small = min(t1.size(),t2.size()) - 1;
			for(int i = 0;i <= fa;++i){
				for(int j = 0;j <= ga;++j){// [i,|s|-j-1] 寻找 
					if(small - j < i)break;
					string s1,s2;s1.reserve(t1.size()-j-i),s2.reserve(t2.size()-j-i);
					for(int idx = i;idx <= t1.size()-1-j;++idx)s1.push_back(t1[idx]);
					for(int idx = i;idx <= t2.size()-1-j;++idx)s2.push_back(t2[idx]);pr.first = s1,pr.second = s2;
					int pos = lower_bound(num+1,num+ln+1,pr)-num;
					if(num[pos] == pr)ans += cnt[pos];
	//				printf("s1 = %s s2 = %s\n",s1.c_str(),s2.c_str());
				}
			}
			cout << ans << '\n';
		}
	}
}
namespace subt2{
	int ln,b[N<<3],lb,lp;ll ans[N];
	struct node{int pre,nxt,idx;}fa[N],fb[N],fc[N],fd[N];// b 前面有多少个，b 后面有多少个
	bool cmp(node n1,node n2){return n1.pre < n2.pre;}
	node read_b(){
		node ans;ans.pre = ans.nxt = 0;char ch;
		while(cin >> ch,ch != 'b')++ans.pre;
		while(ch = cin.get(),ch == 'a')++ans.nxt;
		return ans;
	} 
	pair<int,int> p[N<<2];
	vector<node> mu[N],ku[N];
	int c[N<<3];
	void add(int x,int k){
		for(;x <= lb;x += lowbit(x))c[x] += k;
	}
	ll query(int x){
		ll res = 0;
		for(;x;x ^= lowbit(x))res += c[x];
		return res;
	}
	void solve(){
		for(int i = 1;i <= n;++i){
			fa[i] = read_b(),fb[i] = read_b();b[++lb] = fa[i].nxt,b[++lb] = fb[i].nxt;
			p[++lp] = make_pair(fa[i].nxt-fb[i].nxt,fa[i].pre-fb[i].pre);
	//		printf("%d %d %d %d\n",fa[i].pre,fa[i].nxt,fb[i].pre,fb[i].nxt);
		}
		for(int i = 1;i <= q;++i){
			fc[i] = read_b(),fd[i] = read_b();b[++lb] = fc[i].nxt,b[++lb] = fd[i].nxt;
			p[++lp] = make_pair(fc[i].nxt-fd[i].nxt,fc[i].pre-fd[i].pre);
		}
		sort(p+1,p+lp+1);lp = unique(p+1,p+lp+1)-p-1;sort(b+1,b+lb+1),lb = unique(b+1,b+lb+1)-b-1;
		for(int i = 1;i <= n;++i){
			pii now = make_pair(fa[i].nxt-fb[i].nxt,fa[i].pre-fb[i].pre);int pos = lower_bound(p+1,p+lp+1,now)-p;
			node tmp;tmp.nxt = fa[i].nxt,tmp.pre = fa[i].pre;
			mu[pos].emplace_back(tmp);
		}
		for(int i = 1;i <= q;++i){
	//		printf("%d %d %d %d\n",fc[i].pre,fc[i].nxt,fd[i].pre,fd[i].nxt);
			pii now = make_pair(fc[i].nxt-fd[i].nxt,fc[i].pre-fd[i].pre);int pos = lower_bound(p+1,p+lp+1,now)-p;
			node tmp;tmp.nxt = fc[i].nxt,tmp.pre = fc[i].pre,tmp.idx = i;
			ku[pos].emplace_back(tmp);
		}
		for(int idx = 1;idx <= lp;++idx){
	//		printf("{%d,%d}\n",p[idx].first,p[idx].second);
			sort(mu[idx].begin(),mu[idx].end(),cmp),sort(ku[idx].begin(),ku[idx].end(),cmp);
			int pos = 0;
			for(int i = 0;i < ku[idx].size();++i){
				while(pos < mu[idx].size() && mu[idx][pos].pre <= ku[idx][i].pre){
					mu[idx][pos].nxt = lower_bound(b+1,b+lb+1,mu[idx][pos].nxt) - b;
					add(mu[idx][pos].nxt,1);++pos;
				}
				ku[idx][i].nxt = lower_bound(b+1,b+lb+1,ku[idx][i].nxt) - b;
				ans[ku[idx][i].idx] = query(ku[idx][i].nxt);
			}
			while(pos > 0){--pos;add(mu[idx][pos].nxt,-1);}
		}
		for(int i = 1;i <= q;++i)cout << ans[i] << '\n';
	}
}


int main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> q;
	if(n <= 100 && q <= 100)subt1::solve();
	else subt2::solve();
	return 0;
} 
