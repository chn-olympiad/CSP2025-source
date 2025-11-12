#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],ans,ansx=1,ansy=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	  cin>>a[i];
	for(int i=2;i<=n*m;i++)
	  if(a[i]>a[1])ans++;
	for(int i=1;i<=ans;i++)
	{
		if(ansx%2==1)ansy++;
		else ansy--;
		if(ansy>n)ansy=n,ansx++;
		if(ansy<1)ansy=1,ansx++;
	}
	cout<<ansx<<' '<<ansy;
	return 0;
}

