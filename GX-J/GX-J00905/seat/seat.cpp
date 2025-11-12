#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[15][15];
int flag[150],tot;
int cnt;
bool cmp(int u,int v)
{
	return u>v;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) cin>>flag[++tot];
	cnt=flag[1];
	sort(flag+1,flag+tot+1,cmp);
	for(int i=1;i<=tot;i++)
		if(flag[i]==cnt) cnt=i;
	int lie=(cnt%n==0?cnt/n:cnt/n+1);
	int hang=0;
	if(lie%2==1)
		hang=(cnt%n==0?n:cnt%n);
	else hang=(cnt%n==0?1:n-(cnt%n)+1);
	cout<<lie<<" "<<hang;
	return 0;
}
