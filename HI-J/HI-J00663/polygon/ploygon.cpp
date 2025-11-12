#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
	feropen("ploygon.in","r".stdin);
	freopen("ploygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<a[i]*2+1;
return 0;
 } 
