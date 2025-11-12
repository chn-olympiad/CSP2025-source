#include<bits/stdc++.h>
using namespace std;
int n,m;
int num=1,sum=1;
int a[2500003];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1];
	for(int i=2;i<=n*m;i++){
		if(a[i]>ans){
			sum++;
		}
		if(sum==n+1){
			num++;
			sum=1;
		}
	}
	cout<<num<<" "<<sum;
	return 0;
}
