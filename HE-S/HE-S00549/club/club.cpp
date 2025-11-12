#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,ans=0,a[N],b[N],c[N],an=0;
void ll(long long o,long long p,long long s1,long long s2,long long s3,long long an)
{
	if(s1+s2+s3==n){
		ans=max(an,ans);
		return ;
	}
	for(int i=o+1;i<=n;i++){
		if(s1<n/2){
			ll(i,1,s1+1,s2,s3,an+a[i]);
		}
		if(s2<n/2){
			ll(i,2,s1,s2+1,s3,an+b[i]);
		}
		if(s3<n/2){
			ll(i,3,s1,s2,s3+1,an+c[i]);
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		bool fl=0;
		for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];	
		if(b[i]!=0||c[i]!=0)fl=1;
		}
		if(!fl){
			sort(a+1,a+1+n);
			for(int i=n;i>=n/2+1;i--){
				ans+=a[i];
			}
			cout<<ans<<endl;
			continue;
		}
		bool f[N]={0};
		for(int i=1;i<=n;i++){
			ll(i,1,1,0,0,a[i]);
			ll(i,2,0,1,0,b[i]);
			ll(i,3,0,0,1,c[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
