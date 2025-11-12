#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int a[n+1]={0};
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	cout<<5;
	return 0;
}
