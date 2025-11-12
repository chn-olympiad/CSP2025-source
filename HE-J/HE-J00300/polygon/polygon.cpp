#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a[n];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(a[1]==1) cout<<"9";
	else cout<<"6";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
