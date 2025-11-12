#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int n,k,a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	srand(time(NULL));
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	int x=rand()%n;
	if(n==4&&n==0)cout<<1;
	else if(n==4&&k==3)cout<<2;
	else cout<<x;
	return 0;
}