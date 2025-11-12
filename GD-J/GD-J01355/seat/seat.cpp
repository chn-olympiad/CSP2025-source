#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	int sum=0;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])sum++;
	}
	sum++;
	cout<<sum/n+1<<" ";
	cout<<sum%n;
	return 0;
}
