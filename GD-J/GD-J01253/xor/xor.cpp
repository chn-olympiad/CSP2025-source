//#Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h>
using namespace std;
long long pd[2001000];
long long n,k,s[500500],ans=0;
long long p=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int u=0,r=0;
	pd[0]=2;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		u=u^s[i];
//		if(s[i]==k){
//			ans=ans+1;
//			p=p+n;
//			u=0;
//		}
//		else 
		if(pd[u^k]>=p+1){
//			cout<<ans<<' '<<(u^k)<<' '<<i<<' '<<pd[u^k]<<' '<<p<<endl;
			ans=ans+pd[u^k]-p;
			p=p+n;
			pd[0]=p+1;
			u=0;
		}
		else {
			if(pd[u]<p)pd[u]=p+1;
//			else pd[u]++;
		}
	}
	cout<<ans;
	return 0;
}
