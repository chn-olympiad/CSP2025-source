#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100]={0};
int cnt=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[1]<=a[i])cnt++;
	}
	int ans=cnt/n;
	if(cnt%n==0)
	{
		cout<<ans<<" ";
		if(ans%2==0)
		cout<<1;
		else 
		cout<<n;
	}
	else {
		ans++;
		cout<<ans<<" ";
		if(ans%2==0)
		{
			cout<<n-(cnt%n)+1;
		}
			else cout<<cnt%n;
	}
	
}
