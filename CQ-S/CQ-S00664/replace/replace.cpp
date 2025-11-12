#include<bits/stdc++.h>

using namespace std;
//long long!!!!!!!!!!!!!!!!!!!!
const int N=1e7+20,bas=100,mod=998244353;

long long oo(long long s1,long long s2){
	long long ans=1;
	while(s2){
		if(s2&1)ans=ans*s1%mod;
		s1=s1*s1%mod;
		s2>>=1;
	}
	return ans;
}

long long n,q,pw[N],invpw[N];

long long a[N],hs[N];

long long cnt=0;
map<long long,long long>mp;
multiset<long long>ss[N];
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	invpw[0]=pw[0]=1;
	invpw[1]=oo(bas,mod-2);
	pw[1]=bas;
	for(int i=2;i<N;i++)invpw[i]=invpw[i-1]*invpw[1]%mod,pw[i]=pw[i-1]*pw[1]%mod;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		long long sum1=0,sum2=0;
		for(char v:s1)sum1=(sum1*bas+v-'a'+1)%mod;
		for(char v:s2)sum2=(sum2*bas+v-'a'+1)%mod;
//		cout<<sum1<<" "<<sum2<<"\n";
		if(mp[sum1]==0)mp[sum1]=++cnt;
		ss[mp[sum1]].insert(sum2);
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		long long sum2=0,si=0,ans=0;
		for(char v:s1)si++,hs[si]=(hs[si-1]*bas+v-'a'+1)%mod;
		for(char v:s2)sum2=(sum2*bas+v-'a'+1)%mod;
		for(int l=1;l<=si;l++){
			for(int r=l;r<=si;r++){
				long long kr=(hs[r]-(hs[l-1]*pw[r-l+1]%mod)+mod)%mod;
				long long ksum=(hs[si]-((kr*pw[si-r])%mod)+mod)%mod;//去除之后的hash
				if(mp.find(kr)==mp.end())continue;
				long long t=mp[kr],fi=((sum2-(ksum)%mod+mod)%mod*invpw[si-r])%mod;
//				cout<<l<<" "<<r<<" "<<kr<<" "<<ksum<<" "<<fi<<" "<<ans<<"\n";
				ans+=ss[t].count(fi);//寻找所需要段的hash 
			}
		}
		printf("%lld\n",ans);
	}
	
	
	return 0;
}
