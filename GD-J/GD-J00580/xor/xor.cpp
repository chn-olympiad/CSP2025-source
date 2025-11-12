#include<bits/stdc++.h>
using namespace std;
int n,a,ans=0;
long long k;
bool tmp=false,tmp_1=false,tmp_2=false;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0) tmp=true,tmp_2=true;
	else if(k==1) tmp_1=true;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(a!=1) tmp=false;
		else if(a==0&&tmp_2) ans++;
		else if(a==1&&tmp_1) ans++;
	}
	if(tmp) cout<<0;
	else if(tmp_1) cout<<ans;
	else if(tmp_2) cout<<ans;
	return 0;
 } 
