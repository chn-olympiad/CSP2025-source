#include<bits/stdc++.h>
using namespace std;
long long a[5001],ans=0,n;
bool vis[5001];
//vector<int>c;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>a[3]*2) cout<<1;
		else cout<<0;
		fclose(stdin);
 		fclose(stdout);
		 return 0; 
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
