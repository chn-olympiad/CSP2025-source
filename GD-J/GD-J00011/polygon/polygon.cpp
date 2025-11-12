#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	int ans=0;
	for(int i=3;i<=n;i++){
		int sum=0;
		for(int j=1;j<=n-i+1;j++){
			sum+=j;
		}
		ans+=sum;
	}
	cout<<ans;
}
