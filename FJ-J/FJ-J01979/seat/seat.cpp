#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int i;
	for(i=1;i<=n*m;i++)
	{
		cin>>s[i];
	}
	int r=s[1];
	sort(s+1,s+(m*n)+1);
	reverse(s+1,s+(m*n)+1);
	int t=0;
	for(i=1;i<=n*m;i++)
	{
		if(s[i]==r)
		{
			t=i;
		}
	}
	if(t%n==0)
	{
		cout<<t/n<<" "<<n;
	}
	else
	{
		cout<<t/n+1<<" ";
		if((t/n+1)%2==0)
		{
			cout<<n+1-t%n;
		}
		else
		{
			cout<<t%n;
		}
	}
	return 0;
}
