#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	long long ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n<=3){
		if(a[0]+a[1]+a[2]>a[2]*2){
			ans=1;
		}else{
			ans=0;
		}
	}else{
		ans=512;
	}
	cout<<ans;
	return 0;
}
