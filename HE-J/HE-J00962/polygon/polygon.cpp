#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	int a[5005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
    if(a[0]+a[1]>a[2]&&a[0]+a[2]>a[1]&&a[1]+a[2]>a[0]){
    	ans++;
	}else{
		ans=0;
	}
	cout<<ans;
	return 0;
} 
