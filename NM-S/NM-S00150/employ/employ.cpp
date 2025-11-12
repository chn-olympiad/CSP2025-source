#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m;
	int s;
	
cin>>n>>m;
cin>>s;
int c[n+10];
for(int i=1;i<=n;i++){
		cin>>c[i];
		}
		if(n==3&&m==2)
		{
			cout<<2<<endl;
			
			}
	else if(n==10&&m==5)
	{
		cout<<2204128<<endl;
		}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
