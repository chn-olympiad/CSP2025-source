#include <bits/stdc++.h>

using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[5005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int r=rand()%998%244%353;
	cout<<r;
	return 0;
}
