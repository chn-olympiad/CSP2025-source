#include<bits/stdc++.h>
using namespace std;
int m,n,minn;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int a[n*m+1];
    for(int i=1;i<=n*m;i++)
    {
		if(a[i]<a[1])minn++;
	}
	minn+=1;
	int p=ceil(minn/n);
	cout<<p;
	if(p%2==1)cout<<minn%n;
	else cout<<n-(minn%n)+1;            
} 
