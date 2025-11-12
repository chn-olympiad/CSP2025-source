#include<bits/stdc++.h>
using namespace std;
int a_0[1000100];
int a[1000100];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int diji;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a_0[i];
	}
	int fen=a_0[1];
	sort(a_0+1,a_0+1+n*m);
	for(int i=n*m;i>=1;i--)
	{
		a[i]=a_0[i];
		if(a[i]==fen) diji=n*m+1-i;
	}
	int cnt=0;
	for(int i=1;i<=n*m;i++)
	{
		if(diji/n+1==cnt)
		{
			cout<<cnt<<" ";
			break;
		}
		else cnt++;
	}
	if(n*2%diji==0) cout<<"1";
	else cout<<n*2+1-n*2%diji;
	return 0;
}
