#include<bits/stdc++.h>
using namespace std;
int n,m,p;
int a[110];
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
		cin>>a[i];
	p=a[0];
	sort(a,a+n*m,cmp);
	int j=0;
	while(a[j]!=p) j++;
	int s=j/n+1;
	cout<<s<<" ";
	if(s%2==0)
		cout<<n-j%n;
	else
		cout<<j%n+1;
	return 0;
 } 
