#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int n,m;
int a[N],ar;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	ar=a[1];
	sort(a+1,a+1+n*m);
	int c=1,r=1,flag=1;
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==ar)cout<<c<<" "<<r<<endl;
		if(r+flag>n||r+flag<1)c++,flag=-flag;
		else r+=flag;
	}
	return 0;
}
