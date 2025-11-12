#include<bits/stdc++.h>
using namespace std;
long long a[10000],n,m,s,ms,b[100][100],x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{cin>>a[i];}
	s=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m;j++)
		{if(a[j]<a[j+1]){ms=a[j];a[j]=a[j+1];a[j+1]=ms;}}
	}
	ms=1;x=1;y=1;
	for(int i=1;i<=n*m;i++)
	{
		if(ms==1&&x==n+1){ms=0;x=n;y++;}
		else if(ms==0&&x==0){ms=1;x=1;y++;}
		if(ms==1){b[x][y]=a[i];x++;}
		if(ms==0){b[x][y]=a[i];x--;}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{if(b[i][j]==s){cout<<j<<" "<<i;}}
	}
	cout<<"\n";
	return 0;
}
