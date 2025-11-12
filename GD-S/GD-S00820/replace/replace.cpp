#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN=5e6+5;
int n,q;
struct trie{
	int ch[26];
	int cnt;
}tr[MAXN];
int l=1;
void mem(int t){
	tr[t].cnt=0;
	for(int i=0;i<26;i++)tr[t].ch[i]=0;
}
void ins(int &x,const string& s){
	int head=x;
	for(int i=0;i<s.length();i++){
		if(!tr[head].ch[s[i]-'a']){
			tr[head].ch[s[i]-'a']=++l;
			mem(l);
		}
		head=tr[head].ch[s[i]-'a'];
	}
	tr[head].cnt++;
}
void del(int &x,const string& s){
	int head=x;
	for(int i=0;i<s.length();i++){
		if(!tr[head].ch[s[i]-'a']){
			tr[head].ch[s[i]-'a']=++l;
			mem(l);
		}
		head=tr[head].ch[s[i]-'a'];
	}
	tr[head].cnt--;	
}
int qu(int &x,const string& s){
	int head=x;
	int ans=tr[x].cnt;
	for(int i=0;i<s.length();i++){
		if(!tr[head].ch[s[i]-'a'])break;
		head=tr[head].ch[s[i]-'a'];
		ans+=tr[head].cnt;
	}
	return ans;
}
int mpl;
map<pair<ll,ll>,int>mp;
struct ee{
	string s,t;
	int opt,num;
	vector<ll>ha;
};
bool cmp(const ee& x,const ee& y){
//	if(x.s==y.s){
//		return x.opt<y.opt;
//	}
//	return x.s<y.s;
	if(x.s.length()==0&&y.s.length()==0){
		return x.opt<y.opt;
	}
	if(y.s.length()==0){
		return false;
	}
	if(x.s.length()==0){
		return true;
	}
	if(x.s[0]!=y.s[0]){
		if(x.s[0]==y.s[0]){
			return x.opt<y.opt;
		}
		return x.s[0]<y.s[0];
	}
	int l=1,r=min(x.s.length(),y.s.length()),mid;
	while(l<r){
		mid=(l+r+1)>>1;
		if(x.ha[mid-1]==y.ha[mid-1]){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	if(l==min(x.s.length(),y.s.length())){
		if(x.s.length()==y.s.length())return x.opt<y.opt;
		return x.s.length()<y.s.length();
	}
	if(x.s[l]==y.s[l])return x.opt<y.opt;
	return x.s[l]<y.s[l];
}
const int N=2e5+5;
vector<ee>que[N];
const ll mod=1e16+5;
int sta[N],stal;
int ans[MAXN];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		string s,t;
		cin>>s>>t;
		int ti=0;
		while(ti!=s.length()&&s[ti]==t[ti])ti++;
		if(ti==s.length()){
			continue;
		}
		int tj=s.length()-1;
		while(s[tj]==t[tj]){
			tj--;
		}
		pair<ll,ll>now=make_pair(0,0);
		for(int j=ti;j<=tj;j++){
			now=make_pair((now.first*26+s[j]-'a')%mod,(now.second*26+t[j]-'a')%mod);
		}
//		printf("%lld %lld\n",now.first,now.second);
		if(mp.find(now)==mp.end()){
			mp[now]=++mpl;
		}
		string a="";
		for(int j=ti-1;j>=0;j--)a+=s[j];
		string b="";
		for(int j=tj+1;j<s.length();j++)b+=s[j];
		vector<ll>ha;
		for(int j=ti-1;j>=0;j--){
			if(ha.size()==0){
				ha.push_back(s[j]-'a');
			}else{ll t=ha.back();
				ha.push_back((t*26+s[j]-'a')%mod);
			}
		}
		que[mp[now]].push_back((ee){a,b,0,0,ha});
	}
	for(int i=1;i<=q;i++){
		string s,t;
		cin>>s>>t;
		if(s.length()!=t.length())continue;
		int ti=0;
		while(ti!=s.length()&&s[ti]==t[ti])ti++;
		
		int tj=s.length()-1;
		while(s[tj]==t[tj]){
			tj--;
		}
		pair<ll,ll>now=make_pair(0,0);
		for(int j=ti;j<=tj;j++){
			now=make_pair((now.first*26+s[j]-'a')%mod,(now.second*26+t[j]-'a')%mod);
		}
		if(mp.find(now)==mp.end()){
			mp[now]=++mpl;
		}
		string a="";
		for(int j=ti-1;j>=0;j--)a+=s[j];
		string b="";
		for(int j=tj+1;j<s.length();j++)b+=s[j];
		vector<ll>ha;
		for(int j=ti-1;j>=0;j--){
			if(ha.size()==0){
				ha.push_back(s[j]-'a');
			}else{ll t=ha.back();
				ha.push_back((t*26+s[j]-'a')%mod);
			}
		}
		que[mp[now]].push_back((ee){a,b,1,i,ha});
	}int rt=1;
	for(int i=1;i<=mpl;i++){
//		printf("in\n");
		sort(que[i].begin(),que[i].end(),cmp);
		stal=0;l=1;mem(1);
		for(int j=0;j<que[i].size();j++){
//			printf("%d ",que[i][j].opt);cout<<que[i][j].s<<" "<<que[i][j].t<<"\n";
			while(stal&&(que[i][sta[stal]].s.length()>que[i][j].s.length()||(que[i][sta[stal]].ha.size()&&
			que[i][sta[stal]].ha.back()!=que[i][j].ha[que[i][sta[stal]].s.length()-1]))){
				del(rt,que[i][sta[stal]].t);stal--;
			}
			if(que[i][j].opt==0){
				ins(rt,que[i][j].t);
				sta[++stal]=j;
			}else{
				ans[que[i][j].num]=qu(rt,que[i][j].t);
			}
		}
	}
	for(int i=1;i<=q;i++){
		printf("%d\n",ans[i]);
	}
}
