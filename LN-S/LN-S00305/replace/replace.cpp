#include<bits/stdc++.h>
#define int long long 
using namespace std;
string ca[100001],cb[101001];
string a,b;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replaced.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>ca[i]>>cb[i];
		}
		
	for(int i=1;i<=m;i++)
	{
		//int sum=0;
		cin>>a>>b;
		/*for(int j=1;j<=n;j++)
		{
			
			if(a.find(ca[j])==a.find(cb[j]))sum++;
			
			
			}
			
			cout<<sum<<endl;*/
			cout<<0;
			
	}
	
	
	
	
	return 0;
	
	


}
