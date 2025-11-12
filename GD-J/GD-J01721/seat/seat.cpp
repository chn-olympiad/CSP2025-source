#include<bits/stdc++.h> 
using namespace std;
int n,m,a,s=1,b,c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;cin>>a;
	for(int i=2;i<=n*m;i++)
	{
		cin>>b;
		if(b>a)s++;
	}
//	cout<<s;
	if(s%n!=0)c=s/n+1;
	else c=s/n;
	if(c%2==1)cout<<c<<" "<<(s-1)%n+1;
	else cout<<c<<" "<<n-((s-1)%n); 
	return 0;
}
