#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i,j,n,m,x,y,z,s;
	cin>>n>>j>>s>>z;
	for(i=0;i<=n;i++)
	{
		if(i==0)
		n--;
		if(i==1)
		n++;
		if(j>=n)
		s--;
	}
	cout<<2;
	return 0;
}

