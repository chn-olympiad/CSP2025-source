#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			sort(a+1,a+1+n);
		if(a[i]+a[i+1]>a[1]*2&&a[i]>=3){
			ans++;
		}
		
		}
		
		
	}
	cout<<ans;
	
	return 0;
} 
