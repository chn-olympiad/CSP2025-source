#include<bits/stdc++.h>
using namespace std;
long long T,n,x[4];
long long ans,wi,cnt;
struct a{
	long long int a1,a2,a3,mx,wi;
}a[100001];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	while(T--){
		cin>>n;
		for(long long int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].mx=max(a[i].a1,a[i].a2);
			a[i].mx=max(a[i].mx,a[i].a3);
		}
		for(long long int i=1;i<=n;i++){
			for(long long int j=i+1;j<=n;j++){
				if(a[i].mx<a[j].mx){
					swap(a[i],a[j]);
				}
			}
		}
		for(long long int i=1;i<=n;i++){
			ans+=a[i].mx;
		}
	}
	cout<<ans;
	
	return 0;
}