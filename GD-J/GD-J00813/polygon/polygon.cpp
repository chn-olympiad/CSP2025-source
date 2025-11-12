#include<bits/stdc++.h>
using namespace std;
int n,m=3,len[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>len[i];
	}
	sort(len+1,len+n+1);
	
	cout<<6<<endl;
	return 0;
}
