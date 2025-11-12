#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],t;
bool cmp(int a1,int b1){
	return a1>b1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int tmp=a[1],t1,l=n*m;
	sort(a+1,a+l+1,cmp);
	for(int j=1;j<=l;j++)
		if(a[j]==tmp)
		{
			t=j;
			break;
		}
	if(t%n==0)
	{
		t1=t/n;
		cout<<t/n<<' ';
	}
	else
	{
		t1=t/n+1;
		cout<<t/n+1<<' ';
	}
	if((t1-1)%2==0)
	{
		if(t%n==0)
			cout<<n;
		else
			cout<<t%n;
	}
	else
	{
		if(t%n==0)
			cout<<1;
		else
			cout<<n-(t%n);
	}
	return 0;
}
