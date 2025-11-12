#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==3){
		int z=a[1]+a[2]+a[3];
		sort(a+1,a+4);
		if(z>2*a[3])cout<<1;
		else cout<<0;
		return 0;
	}
	int b=0;
	if(n>=4){
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<=n;k++){
					int z=a[i]+a[j]+a[k];
					int t=max(a[i],max(a[j],a[k]));
					if(z>t*2){
						b++;
					}
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						int z=a[i]+a[j]+a[k]+a[l];
						int t=max(a[i],max(a[j],(max(a[k],a[l]))));
						if(z>2*t){
//							cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
							b++;
						}
					}
				}
			}
		}
	}
	if(n>=5){
		b+=(n-4);
	}
	cout<<b;
	return 0;
}

