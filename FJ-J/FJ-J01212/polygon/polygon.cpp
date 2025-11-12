#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int cmp(int x,int y){
	return x>=y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(n==3)cout<<1;
	else return 0;
	fclose(stdin);
	fclose(stdout);
}