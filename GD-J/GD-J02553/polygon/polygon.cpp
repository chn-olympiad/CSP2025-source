#include<bits/stdc++.h>
using namespace std;
int n,a[5000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	if(n==3){
		if(a[0]+a[1]>a[2])cout<<1;
		else cout<<0;
	}
	else if(a[n-1]==1)cout<<n*(n-1)*(n-2)/2/3;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
