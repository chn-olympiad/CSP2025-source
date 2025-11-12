#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,s,c[100005],ans=1;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=m;i++){
		ans*=i;
		}
	ans%=998244353;	
	cout<<ans<<endl;
	return 0;
}
