#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int ans=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i!=1&&a[i]>a[1]) 
			ans++;
	}
	int r=(ans/(n*2))*2;
	int f=(ans%(n*2));
	if(f>n) r++,f-=n,f=(n-f+1);
	if(f>0) r++;
	cout<<r<<" "<<f;
	return 0;
}
