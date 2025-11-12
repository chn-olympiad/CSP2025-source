#include<bits/stdc++.h>
#define ll long long
#define N 120000
using namespace std;
ll t,n;
ll a[N],b[N],c[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ll sum=0,ans1=0,ans2=0,ans3=0;
		ll f[4]={0};
		for(ll i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			ans1+=a[i];
			ans2+=b[i];
			ans3+=c[i];
		}
		if(n==2){
			ll l1[4]={0,a[1],b[1],c[1]};
			ll l2[4]={0,a[2],b[2],c[2]};
			sort(l1+1,l1+3);
			sort(l2+1,l2+3);
			sum=max(l1[1]+l2[2],l1[2]+l2[1]);
		}
		else{
			for(ll i=1;i<=n;i++){
				ll maxs=0,maxi=0,maxp=0;
				for(ll j=1;j<=n;j++){
					if(maxs<=a[i]&&f[1]<=n/2){
						maxs=a[i];
						maxi=i;
						maxp=1;
					}
					if(maxs<=b[i]&&f[2]<=n/2){
						maxs=b[i];
						maxi=i;
						maxp=2;
					}
					if(maxs<=c[i]&&f[3]<=n/2){
						maxs=c[i];
						maxi=i;
						maxp=3;
					}
				}
				sum+=maxs;
				a[maxi]=0,b[maxi]=0,c[maxi]=0;
				f[maxp]++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

