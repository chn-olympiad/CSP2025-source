#include<bits/stdc++.h>
using namespace std;
bool cmd(int a,int b){
	return a>b;
}
int n,m,a[1000],b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	b=a[1];
	sort(a+1,a+n*m+1,cmd);
	for(int i=1;i<=n*m;i++)
	if(a[i]==b)
	{
		b=i;
		break;
	}
	for(int i=1;i<=m;i++)
	{
		if(b>n) b-=n;
		else 
		{
			cout<<i<<" ";
			if(i%2==0) cout<<n-b+1;
			else cout<<b;
			return 0;
		}
	}
	return 0;
}
