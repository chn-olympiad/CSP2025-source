#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=1;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		ans=ans*i;
	}
	cout<<((ans%998)%244)%353;
 } 
