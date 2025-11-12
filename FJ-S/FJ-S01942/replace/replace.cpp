#include<bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define Y second
#define ll long long
using namespace std;
inline void dd(int &xx){
	xx=0;
	int ff=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') ff=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		xx=xx*10+ch-'0';
		ch=getchar();
	}
	xx*=ff;
}
const int N=5e6+5;
const ll mod=3e9+21;
int n,q;
char a[N],b[N];
ll hh(int x,int y){
	ll sum=0;
	for(int i=x;i<=y;++i){
		sum=(sum*121ll%mod+a[x])%mod;
	}
	for(int i=x;i<=y;++i){
		sum=(sum*121ll%mod+b[x])%mod;
	}
	return sum;
}
int cnt=1,rt=1,son[N][26],f[N],h[N];
unordered_map<ll,int> mp[N]; 
void add(char gh[],int len,ll hz){
	int p=rt;
	for(int i=1;i<=len;++i){
		int x=gh[i]-'a';
		if(!son[p][x]) son[p][x]=++cnt;
		p=son[p][x];
	}
	++mp[p][hz];
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	dd(n),dd(q);
	for(int i=1;i<=n;++i){
		int len=0;
		scanf("%s",a+1);
		scanf("%s",b+1);
		len=strlen(a+1);
		int minn=len+1,maxn=0;
		for(int j=1;j<=len;++j){
			if(a[j]!=b[j]){
				minn=min(minn,j),maxn=max(maxn,j);
			}
		}
		if(minn==len+1) continue;
		ll hz=hh(minn,maxn);
		add(a,len,hz*(len-maxn+1)%mod);
	}
//	cerr<<cnt<<endl;
	int l=0,r=0;
	for(int i=0;i<26;++i){
		if(son[rt][i]){
			f[son[rt][i]]=rt;
			h[++r]=son[rt][i];
		}
	}
//	cerr<<"ksal"<<endl;
	while(l<r){
		++l;
		int p=h[l];
		for(int i=0;i<26;++i){
			if(son[p][i]){
				f[son[p][i]]=son[f[p]][i];
				h[++r]=son[p][i];
			}else{
				son[p][i]=son[f[p]][i];
			}
		}
	}
//	cerr<<"aslksa"<<endl;
	for(int tt=1;tt<=q;++tt){
		scanf("%s",a+1),scanf("%s",b+1);
		int len=strlen(a+1);
		if(len!=(int)strlen(b+1)){
			printf("0\n");
			continue;
		}
		int minn=len+1,maxn=0;
		for(int j=1;j<=len;++j){
			if(a[j]!=b[j]){
				minn=min(minn,j),maxn=max(maxn,j);
			}
		}
		ll hz=hh(minn,maxn);
		int p=rt,ans=0;
		for(int i=1;i<=len;++i){
			int x=a[i]-'a';
			p=son[p][x];
			int yu=p;
			while(yu&&i>=maxn){
				ll ou=hz*(i-maxn+1)%mod;
				if(mp[yu].find(ou)!=mp[yu].end()){
					ans+=mp[yu][ou];
				}
				yu=f[yu];
			}
		}
		printf("%d\n",ans);
	}
}
