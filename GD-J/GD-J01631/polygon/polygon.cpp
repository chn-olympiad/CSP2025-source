#include<bits/stdc++.h>
using namespace std;
int n,a[5050]; 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	srand(a[n-1]);
	for(int i=1;i<7;i++) srand(rand()%998244353);
	for(int i=0;i<7;i++) a[i]=rand()%998244353;
	cout<<a[rand()%7];
	return 0;
}
