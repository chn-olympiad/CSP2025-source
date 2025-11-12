#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mkp make_pair
using namespace std;
const int N=2e5+5,h1=37,mod=998244353;
string read(){
	string st;char ch=getchar();
	while(ch>'z'||ch<'a')ch=getchar();
	while(ch>='a'&&ch<='z')st=st+ch,ch=getchar();
	return st;
}
int n,m,k,q;
int cnt;
int siz[N],pos[N];
set<pair<ll,ll> >h[3200];
int pw[5000000+5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<=5e6;i++)pw[i]=pw[i-1]*h1%mod;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1=read(),s2=read(); 
		ll hash1=0,hash2=0;
		m=s1.size();
		if(!pos[m])pos[m]=++cnt,siz[cnt]=m;
		for(int j=0;j<m;j++){
			hash1=(hash1*h1%mod+s1[j]-'a'+1)%mod,
			hash2=(hash2*h1%mod+s2[j]-'a'+1)%mod;}
			
		h[pos[m]].insert(mkp(hash1,hash2));
	//	printf("%lld %lld \n",hash1,hash2);
	}
	while(q--){
		string s1=read(),s2=read(); 
		ll l=-1,r,len,ans=0;
		m=s1.size();
		for(int i=0;i<m;i++)
			if(s1[i]!=s2[i])l=(l==-1)?i:l,r=i;
		len=r-l+1;
	//	printf("len%d l%d r%d\n",len,l,r);
		for(int i=len,L,R;i<=m;i++){
			if(!pos[i])continue;
			L=max(r-i+1,0ll);
			R=L+i-1;
		//	printf("**len%d L%d R%d\n",i,L,R);
			ll hash1=0,hash2=0;
			for(int j=L;j<=R;j++)
				hash1=(hash1*h1%mod+s1[j]-'a'+1)%mod,
				hash2=(hash2*h1%mod+s2[j]-'a'+1)%mod;
			//	printf("*%d %lld %lld \n",j,hash1,hash2);
			while(R<m&&L<=l){
		//		printf("*%lld %lld \n",hash1,hash2);
				ans+=h[pos[i]].count(mkp(hash1,hash2));
				if(++R==m||L==l)break;
				hash1=((hash1+mod-pw[len-1]*(s1[L]-'a'+1)%mod)%mod*h1%mod+s1[R]-'a'+1)%mod;
				hash2=((hash2+mod-pw[len-1]*(s2[L]-'a'+1)%mod)%mod*h1%mod+s2[R]-'a'+1)%mod;
				L++;
			}
		}printf("%lld\n",ans);
	}
	return 0;
}/*
aaaaaba
aaaaaaa

aaaab
b a*/
