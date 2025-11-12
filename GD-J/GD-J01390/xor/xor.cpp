#include<bits/stdc++.h> 
//#define int long long
using namespace std;
const int maxn=5e5+5,maxm=(1<<21)+5;
int n,m,a[maxn],b[maxm],k;
int s=0,r=-1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]^=a[i-1];
	}
	for(int i=0;i<maxm;i++)b[i]=-2;
	b[0]=0;
	for(int i=1;i<=n;i++)
	{
//		cout<<a[i]<<' ';
		int t=(a[i]^k);
		if(b[t]>=r)
		{
			r=i;
			s++;
		}
		b[a[i]]=i;
	}
	cout<<s;
	return 0;
}
