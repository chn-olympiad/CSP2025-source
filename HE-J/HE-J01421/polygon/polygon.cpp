#include<bits/stdc++.h>
using namespace std;
int ff(int x)
{
	if(x==1)return x;
	else return x%998244353*ff(x-1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,b,c,d,e,i,j,k,l,x,y,n;
	int g[5002]={0};
	cin>>n;
	for(i=1;i<=n;i++)
	    cin>>g[i];
	cout<<ff(n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
