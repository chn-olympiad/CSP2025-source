#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c,h;  
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int y=1;y<=t;y++)
	{
		cin>>n;
		for(int m=1;m<=n;m++)
		{
			cin>>a>>b>>c;
			h+=max(a,max(b,c));
		}
		cout<<h<<endl;
		h=0;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
