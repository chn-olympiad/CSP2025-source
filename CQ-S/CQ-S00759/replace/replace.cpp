#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,bs=233,mod=1e9+7,bs2=97,mod2=998244353;
int n,Q,pw1[N],pw2[N];
map<pair<long,long>,int>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>Q;
	for(int k=1;k<=n;k++){
		string x,y;
		cin>>x>>y;
		int len=x.length();
		int ax=0,bx=0,ay=0,by=0;
		for(int i=0;i<len;i++){
			ax=(1ll*ax*bs%mod+x[i]-'a'+1)%mod;
			bx=(1ll*bx*bs2%mod2+x[i]-'a'+1)%mod2;
			ay=(1ll*ay*bs%mod+y[i]-'a'+1)%mod;
			by=(1ll*by*bs2%mod2+y[i]-'a'+1)%mod2;
		}
		mp[{1ll*ax*bx,1ll*ay*by}]++;
	}
	pw1[0]=pw2[0]=1;
	for(int i=1;i<N;i++){
		pw1[i]=1ll*pw1[i-1]*bs%mod;
		pw2[i]=1ll*pw2[i-1]*bs2%mod2; 
	}
	while(Q--){
		string s,t;
		cin>>s>>t;
		int l1=s.length(),l2=t.length();
		if(l1!=l2){
			cout<<"0\n";
			continue;
		}
		s=' '+s;
		t=' '+t;
		int L=0,R=l1+1;
		for(int i=1;i<=n;i++)
			if(s[i]!=t[i]){
				L=i;
				break;
			}
		for(int i=n;i;i--)
			if(s[i]!=t[i]){
				R=i;
				break;
			}
		long long ans=0;
		for(int i=1;i<=L;i++){
			int ax=0,bx=0,ay=0,by=0;
			for(int j=i;j<=l1;j++){
				ax=(1ll*ax*bs%mod+s[j]-'a'+1)%mod;
				bx=(1ll*bx*bs2%mod2+s[j]-'a'+1)%mod2;
				ay=(1ll*ay*bs%mod+t[j]-'a'+1)%mod;
				by=(1ll*by*bs2%mod2+t[j]-'a'+1)%mod2;
//				cout<<i<<" "<<j<<":"<<ax<<" "<<by<<" "<<ay<<" "<<by<<"--\n";
				long long x=1ll*ax*bx,y=1ll*ay*by;
				if(j>=R&&mp.count({x,y}))ans+=mp[{x,y}];
//				cout<<ans<<" LLLL\n";
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

