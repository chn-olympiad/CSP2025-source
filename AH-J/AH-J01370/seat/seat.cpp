#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct aaa
{
	int b,id;
}a[100001];
bool cmp(aaa x,aaa y)
{
	return x.b>y.b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].b;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	int i=1;
	for(i=1;i<=m;)
	{
		for(int j=1;j<=n;j++)
		{
			cnt++;
			if(a[cnt].id==1)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
		i++;
		for(int j=n;j>=1;j--)
		{
			cnt++;
			if(a[cnt].id==1)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
		i++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
一开始i++写外面去了...
看了半天
*/
