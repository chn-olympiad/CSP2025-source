#include<bits/stdc++.h>
using namespace std;
int a[1000];
bool cmp(int x,int y)
{
	return x>=y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int p,cnt;
	int hang,lie;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+1+n*m,cmp); 
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==p)
		cnt=i;
	}
	if(cnt%m==0)
	{
		lie=cnt/m;
	}
	else
	{
		lie=cnt/m+1;
	}
	if(lie%2==1)
	{
		hang=cnt%m;
	}
	else
	{
		hang=(m+1)-(cnt%m);
	}
	cout<<lie<<" "<<hang;
	return 0;
	}
