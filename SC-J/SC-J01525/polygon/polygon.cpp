#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	if(n<3)cout<<0;
	else if(n==3){
		if(a[0]+a[1]>a[2])cout<<1;
		else cout<<0;
	}
	else cout<<n-2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}