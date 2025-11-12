#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void write(int k){
	if(k<0){
		k=-k;
		putchar('-');
	}
	if(k>9)
		write(k/10);
	putchar(k%10+'0');
}
/*
显然找出区间[l,r]表示字符被改变极大区间,Hash后假设是a->b,假设前面的长度为x,Hash值为c,后面的长度为y,Hash值为d
对于a,b,x,c这四个信息显然可以枚举,然后考虑快速查询满足条件的y,d的个数
考虑预处理出,对于a,b,x,c相同的串,y,d可以根据是不是前缀进行dp,维护dp[y'][d']表示如果y=y',d=d'的时候答案为多少,而且因为总长度只有L1,所以也可以处理出y,d对应的点在哪里
查询的时候二分出最后一个有对应点的y,d就行了

dzd助我破鼎！莫卡Hash！
*/
const ull mod=1e9+7,P=13333331;
const int V=5e6;
ull pn[5000005],H1[5000005],H2[5000005];
int n,q;
char s1[5000005],s2[5000005];
struct node{
	ull a,b,len,x,c;
};
ull g(int l,int r,ull *H){
	return (H[r]-H[l-1]*pn[r-l+1]%mod+mod)%mod;
}
ull f(node x){
	ull v=(x.a*pn[x.len+x.x]+x.b*pn[x.x]+x.c)%mod;
	return v*P+x.x;
}
unordered_map<ull,node> h1;
unordered_map<ull,vector<pair<int,vector<ull> > > > h2;
unordered_map<ull,vector<int> > h3,h4;
unordered_map<ull,unordered_map<ull,int> > h6;
unordered_map<ull,vector<int> > h5;
vector<pair<int,vector<ull> > > d;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pn[0]=1;
	for(int i=1;i<=V;i++){
		pn[i]=pn[i-1]*P%mod;
	}
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		scanf("%s%s",s1+1,s2+1);
		int len=strlen(s1+1),l=0,r=0;
		for(int j=1;j<=len;j++){
			H1[j]=(H1[j-1]*P%mod+s1[j]-'a'+1)%mod;
			H2[j]=(H2[j-1]*P%mod+s2[j]-'a'+1)%mod;
		}
		for(int j=1;j<=len;j++){
			if(s1[j]!=s2[j]){
				if(!l)
					l=j;
				r=j;
			}
		}
		node res;
		res.a=g(l,r,H1),res.b=g(l,r,H2),res.x=l-1,res.c=g(1,l-1,H1),res.len=r-l+1;
		vector<ull> now;
		if(r<len)
			now.emplace_back(s1[r+1]-'a'+1);
		for(int j=r+2;j<=len;j++){
			now.emplace_back((now.back()*P%mod+s1[j]-'a'+1)%mod);
		}
		h1[f(res)]=res,h2[f(res)].emplace_back(pair<int,vector<ull> >{len-r,now}),h3[f(res)].emplace_back(0),h4[f(res)].emplace_back(-1);
	}
	int num=0;
	for(auto &i:h2){
		d=i.second;
		vector<int> id;
		for(int j=0;j<d.size();j++){
			id.emplace_back(j);
		}
		sort(id.begin(),id.end(),[](int x,int y){
			return d[x].first>d[y].first;
		});
		int now=d[id[0]].first+1;
		unordered_set<int> p;
		h5.clear();
		for(int j=0;j<d.size();j++){
			if(now!=d[id[j]].first){
				for(auto &r:p){
					h5[d[id[j]].first?d[r].second[d[id[j]].first-1]:0].emplace_back(r);
				}
				now=d[id[j]].first;
			}
			if(h5.find(d[id[j]].first?d[id[j]].second.back():0)!=h5.end()){
				for(auto r:h5[d[id[j]].first?d[id[j]].second.back():0]){
					h4[i.first][r]=id[j];
					p.erase(r);
				}
				h5[d[id[j]].first?d[id[j]].second.back():0].clear();
			}
			p.emplace(id[j]);
			h5[d[id[j]].first?d[id[j]].second[d[id[j]].first-1]:0].emplace_back(id[j]);
		}
		int flag=1;
		if(d[id[d.size()-1]].first){
			flag=0;
			h3[i.first].emplace_back(0),h4[i.first].emplace_back(-1),h6[i.first][0]=d.size(),id.emplace_back(d.size());
			for(int j=0;j<d.size();j++){
				if(h4[i.first][j]==-1)
					h4[i.first][j]=d.size();
			}
			d.emplace_back(pair<int,vector<ull> >{0,{}});
		}
		for(int j=d.size()-1;j>=0;j--){
			if(h4[i.first][id[j]]!=-1){
				h3[i.first][id[j]]=h3[i.first][h4[i.first][id[j]]]+1;
				for(int k=d[id[j]].first-1;k>d[h4[i.first][id[j]]].first;k--){
					h6[i.first][d[id[j]].second[k-1]]=h4[i.first][id[j]];
				}
			}
			else
				h3[i.first][id[j]]=flag;
			h6[i.first][d[id[j]].first?d[id[j]].second.back():0]=id[j];
		}
	}
	while(q--){
		scanf("%s%s",s1+1,s2+1);
		if(strlen(s1+1)!=strlen(s2+1)){
			write(0),putchar('\n');
			continue;
		}
		int l=0,r=0,len=0;
		len=strlen(s1+1);
		for(int i=1;i<=len;i++){
			if(s1[i]!=s2[i]){
				if(!l)
					l=i;
				r=i;
			}
		}
		for(int j=1;j<=len;j++){
			H1[j]=(H1[j-1]*P%mod+s1[j]-'a'+1)%mod;
			H2[j]=(H2[j-1]*P%mod+s2[j]-'a'+1)%mod;
		}
		node res;
		res.a=g(l,r,H1),res.b=g(l,r,H2),res.x=l-1,res.c=g(1,l-1,H1),res.len=r-l+1;
		int ans=0;
		for(int i=0;i<=l-1;i++){
			res.x=i,res.c=g(l-i,l-1,H1);
			if(h6.find(f(res))==h6.end())
				continue;
			int L=r,R=len+1;
			while(L<R){
				int mid=(L+R)>>1;
				if(h6[f(res)].find(g(r+1,mid,H1))!=h6[f(res)].end())
					L=mid+1;
				else
					R=mid;
			}
			if(L>r)
				ans+=h3[f(res)][h6[f(res)][g(r+1,L-1,H1)]];
		}
		write(ans),putchar('\n');
	}
	return 0;
}