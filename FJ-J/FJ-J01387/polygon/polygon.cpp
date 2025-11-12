#include<bits/stdc++.h> 
using namespace std;
long long n,a[10005],num,v[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i]; 
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=1;i+j<n;j++){
			for(int k=2;i+k<n;k++){
				if(a[i]+a[i+j]>=a[i+k]&&a[i]+a[i+k]>=a[i+j]&&a[i+k]+a[i+j]>=a[i]){
					num++;
				}	
			}
		}	
	}
	cout<<num%998244353;
	return 0;
}
