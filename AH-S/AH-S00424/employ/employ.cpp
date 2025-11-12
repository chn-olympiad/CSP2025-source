#include<bits/stdc++.h>
const int N = 510;
char a[N];
int k[N];
using namespace std;
int main()
{
	int m,n,ans=0;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>k[i];
		if(k[i]>0)ans++;
	}
	cout<<ans*n%998244353;
	return 0;
}
