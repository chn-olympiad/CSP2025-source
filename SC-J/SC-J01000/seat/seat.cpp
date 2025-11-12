#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r,cnt=1;
bool cmp(int a,int b)
{
	return a>b;
}
void add(int &i,int &j)
{
	if(i&1)
	{
		j++;
		if(j>n) i++,j=n;
	}else
	{
		j--;
		if(j<1) i++,j=1;
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1) r=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int i=1,j=1;
	while(a[cnt]!=r)
	{
		cnt++;
		add(i,j); 
	}
	cout<<i<<' '<<j;
	return 0;
}