#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,q,n;
map<string,map<string,ll> >s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&N,&q);
	for(ll i=1;i<=N;i++){
		string sa,sb;
		cin>>sa>>sb;
		s[sa][sb]++;
	}
	while(q--){
		string ta,tb;
		ll ans=0;
		cin>>ta>>tb;
		n=ta.size();
		ll r=-1,l=-1;
		string sda,sdb;
		for(ll i=0;i<n;i++){
			if(ta[i]!=tb[i]){
				r=i;
				if(l==-1)l=r;
			}
		}
		for(ll i=l;i<=r;i++)sda+=ta[i],sdb+=tb[i];
		//cout<<sda<<" "<<sdb<<endl;;
		ll bt=r-l+1;
		for(ll si=0;si<=n-bt;si++){
			ll i=0;
			for(i=max(i,si-n+r+1);i<=min(si,l);i++){
				string sfa,sfb;
				for(ll j=l-i;j<l;j++){
					sfa+=ta[j];
					sfb+=tb[j];
				}
				sfa+=sda,sfb+=sdb;
				for(ll j=r+1;j<=si-i+r;j++){
					sfa+=ta[j];
					sfb+=tb[j];
				}
				ans+=s[sfa][sfb];
			//	cout<<sfa<<" "<<sfb<<endl;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
±©Á¦£º
Ã¶¾Ùq£¬ÕÒ²»Í¬´®
Ã¶¾Ù×Ö´®£¬Ìæ»»£¬ÀÛ¼Æ´ð°¸ 
*/ 
