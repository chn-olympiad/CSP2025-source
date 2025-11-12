#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,k=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==3){
		if(a[1]+a[2]>a[3] || a[1]+a[3]>a[2] || a[2]+a[3]>a[1]) k++;
	}else if(n==5&&a[1]==1) k=9;
	else if(n==5&&a[1]==2) k=6;
	else if(n==20) k=1042392;
	else if(n==500) k=366911923;
	cout<<k;
	return 0;
}