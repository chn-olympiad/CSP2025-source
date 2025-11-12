#include<bits/stdc++.h>
using namespace std;

int n;
int a[5050];
int ans=0;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		int sum=a[1]+a[2]+a[3];
		int Max=max(a[1],max(a[2],a[3]));
		if(sum>Max*2) cout<<1;
		else{
			cout<<0;
		}
		return 0;
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j+i-1<=n;j++){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
