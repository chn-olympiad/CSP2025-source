#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	
	freopen("seat.out","w",stdout);
	int n,m,a,b;
	int c[101],s[101];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>c[i];
        s[1]=100;
	}
	if(m%2==0)
	{
		b=(s[1]-c[1])/m+1;	
	    cout<<b<<" ";
	    a=(s[1]-c[1]-1)%n;
	    if(a==0)
	    cout<<n;//行数，但要先输出列数 
	    else cout<<(s[1]-c[1]+1)%n+1;
		
	}
	else
	{
		b=(s[1]-c[1]-1)/n;
	if(b==0)
	{
	b=b+1;
	cout<<b<<" ";
	}
	else cout<<b<<" ";
	a=(s[1]-c[1]-1)%m;
	if(a==0)
	cout<<n;//行数，但要先输出列数 
	else cout<<a;
		
	}
	return 0;
}
