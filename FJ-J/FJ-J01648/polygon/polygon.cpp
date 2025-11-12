#include<bits/stdc++.h>
using namespace std;
long long n,m=-10,sum=0,a[6005],ans=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>m){
			m=a[i];
		}
		sum+=a[i];
	}
	if(n<3){
		ans=0;
	}
	else if(n==3){
		if(sum<=m*2){
			ans=0;
		}
	}
	else{
		ans=n;
	}
	cout<<ans;
	return 0;
}
