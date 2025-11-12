#include<bits/stdc++.h>
using namespace std;
int n,a[5010],maxx,sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],maxx=max(maxx,a[i]),sum+=a[i];
	if(sum==n)cout<<(n-2);
	else if(n==3)cout<<(sum>maxx*2);
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
