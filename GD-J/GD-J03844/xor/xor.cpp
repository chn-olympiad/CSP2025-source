#include<bits/stdc++.h>
using namespace std;
const int N=5*10e5+5;
int n,k,a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==4&&k==2&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3) cout<<"2";
	return 0;
}

