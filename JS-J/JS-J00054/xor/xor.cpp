#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N];
map<int,int>ord;
int las[N];
int ans;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int xorsum=0;
	for(int i=1;i<=n;i++)
	{
		xorsum^=a[i];
		if(ord[xorsum^k])las[i]=ord[xorsum^k]+1;
		else if(xorsum==k)las[i]=1;
		else las[i]=-1;
		ord[xorsum]=i;
		//cerr<<xorsum<<" "<<las[i]<<endl;
	}
	int r=0;
	for(int i=1;i<=n;i++)
		if(las[i]>r)r=i,ans++;
	cout<<ans<<endl;
	return 0;
}
