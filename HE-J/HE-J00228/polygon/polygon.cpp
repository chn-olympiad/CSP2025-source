#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a[6000],c=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=3;i<=n;i++){
		for(int k=1;k<=n-i;k++){
			long long s=0,ma=INT_MIN;
			for(int j=k+1;j<=i+k;j++){
				s+=a[j];
				ma=max(ma,a[j]);
			}
			if(s>ma*2)c++;
		} 
	}cout<<c%998%244%353;
	return 0;
}
