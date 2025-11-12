#include<bits/stdc++.h>
using namespace std;
int a[110],n,m,k,s,f;
bool cmp(int a,int b)
{
	if(a>=b) return true;
	else if(a<b) return false;
}
int l(int y)
{
	if(y==0) return y;
	else return 1;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+s+1,cmp);
	for(int i=1;i<=s;i++)
	{
		if(a[i]==k)
		{
			k=i;
			break;
		}
	}
	f=k%n;
	if((k/n+l(f))%2==0)
	{
		if(k%n==0) cout<<k/n<<" "<<1;
		else cout<<k/n+1<<" "<<n-k%n+1;
	} 
	else 
	{
		if(k%n==0) cout<<k/n<<" "<<n;
		else cout<<k/n+1<<" "<<k%n;
	}
}
