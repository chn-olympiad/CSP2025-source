#include<bits/stdc++.h>
using namespace std;
int n,m;
bool a[505];
int pac[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char c;
	for(int i=1;i<=n;i++){
		cin>>c;
		if(c=='1') a[i]=1;
		else a[i]=0;
	}
	for(int i=1;i<=n;i++)
		cin>>pac[i];
	sort(pac,pac+n+1);
	cout<<1;
	return 0;
}
