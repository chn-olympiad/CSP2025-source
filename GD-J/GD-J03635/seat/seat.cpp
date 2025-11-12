#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int sc=a[1],num;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) if(a[i]==sc) num=i;
	int lie=num/n;
	if(lie*n!=num) lie++;
	if(lie%2==1)
	{
		int hang=num%n;
		if(hang==0) hang=n;
		cout<<lie<<" "<<hang<<endl;
	}
	else
	{
		int hang=num%n;
		if(hang==0) hang=n;
		cout<<lie<<" "<<n-hang+1<<endl;
	}
	return 0;
}
