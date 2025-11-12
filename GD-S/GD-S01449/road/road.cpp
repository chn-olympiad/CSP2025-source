#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t,m;
	cin>>t;cin>>m;
	cout<<t*6<<' '<<m<<t*6-m-1;
	fclose(stdout);
	fclose(stdin);
	return 0;
}
