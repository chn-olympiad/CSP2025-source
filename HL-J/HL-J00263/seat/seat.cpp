#include<bits/stdc++.h>
using namespace std;
string str;
int s[105],r,n,m;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
		cin>>s[i];
	r=s[0];
	sort(s,s+n*m,cmp);
	for(int i=0;i<n*m;i++)
		if(s[i]==r)
		{
			cout<<i/n+1<<' ';
			if((i/n+1)%2==0)
				cout<<n-i%n<<"\n";
			else
				cout<<i%n+1<<"\n";
			return 0;
		}
	return 0;
}