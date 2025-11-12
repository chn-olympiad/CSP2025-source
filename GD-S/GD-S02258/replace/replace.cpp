#include<bits/stdc++.h>
using namespace std;
#define N 200005 
#define M 5000005
#define int long long
const int mod = 998244353,bas = 131;
int n,m,i,j,ans,q,pos,len[N],vs[N],vt[N],L[N],R[N],val[N][4];
int qs[M],qt[M],pw[M];
char ss[M],tt[M];
string s[N],t[N];
int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1,a=a*a%mod;
	}
	return res;
}
int calcs(int ll,int rr){
	return (qs[rr]-qs[ll-1]+mod)*pw[ll-1]%mod;
}
int calct(int ll,int rr){
	return (qt[rr]-qt[ll-1]+mod)*pw[ll-1]%mod;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	pos=1,pw[0]=1;
	for(i=1;i<=5000000;i++) pos=pos*bas%mod,pw[i]=qpow(pos,mod-2);
	for(i=1;i<=n;i++){
		cin>>s[i]>>t[i];
		len[i]=s[i].size();
		int p=1;
		for(j=0;j<len[i];j++){
			vs[i]=(vs[i]+p*(s[i][j]-'a'+1)%mod)%mod;
			p=p*bas%mod;
		}
		p=1;
		for(j=0;j<len[i];j++){
			vt[i]=(vt[i]+p*(t[i][j]-'a'+1)%mod)%mod;
			p=p*bas%mod;
		}
		L[i]=0,R[i]=len[i]-1;
		while(L[i]<len[i] && s[i][L[i]]==t[i][L[i]]) L[i]++;
		while(R[i]>=0 && s[i][R[i]]==t[i][R[i]]) R[i]--;
		p=1;
		for(j=L[i];j<=R[i];j++){
			val[i][1]=(val[i][1]+p*(s[i][j]-'a'+1)%mod)%mod;
			p=p*bas%mod;
		}
		p=1;
		for(j=L[i];j<=R[i];j++){
			val[i][2]=(val[i][2]+p*(t[i][j]-'a'+1)%mod)%mod;
			p=p*bas%mod;
		}
	}
	while(q--){
		scanf("%s%s",ss+1,tt+1);
		int ls=strlen(ss+1),lt=strlen(tt+1);
		if(ls!=lt){
			puts("0");
			continue;
		}
		int l=1,r=ls,p=1;
		while(l<=ls && ss[l]==tt[l]) l++;
		while(r>=1 && ss[r]==tt[r]) r--;
		for(i=1;i<=ls;i++){
			qs[i]=(qs[i-1]+p*(ss[i]-'a'+1)%mod)%mod;
			p=p*bas%mod;
		}
		p=1;
		for(i=1;i<=ls;i++){
			qt[i]=(qt[i-1]+p*(tt[i]-'a'+1)%mod)%mod;
			p=p*bas%mod;
		}
		ans=0;
		for(i=1;i<=n;i++){
			if(calcs(l,r)!=val[i][1] || calct(l,r)!=val[i][2] || len[i]>ls) continue;			
			if(calcs(l-L[i],r+len[i]-R[i]-1)==vs[i] && calct(l-L[i],r+len[i]-R[i]-1)==vt[i]) ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//zjojxhmkzosbfsrzoytcbjmouamvjtearyierexqrvbwti  uyucqryhrjmrrcmfastozgdyvnnejyokornvimwzaijuqsienpfofktwhydvztgxpavjrp sndwydcdsptolyoikshfbftmbyhqitcpgxvv
//zjojxhmkzosbfsrzoytcbjmouamvjtearyierexqrvbwti  nhvarpmcurogqsjnsymlzdmvilobyooplzkfvkhegxzrvcygauplfuyfkyakftyyxdsdsw sndwydcdsptolyoikshfbftmbyhqitcpgxvv
