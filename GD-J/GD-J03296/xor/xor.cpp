#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
const int K=(1<<21);
int n,k,l,a[N+5],b[K+5],sum,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;l=0;b[0]=0;
	for(int i=1;i<K;i++) b[i]=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum^=a[i];
		if(b[sum^k]>=l) ans++,l=i;
		b[sum]=i;
	}
	cout<<ans;
	return 0;
}
/*
froepen("number.in","r",stdin);
froepen("number.out","w",stdout);
freopem("number.in","r",stdin);
freopem("number.out","w",stdout);
上面这些东西都是用来诈骗你的 awa
我猜数组没开够的人<114514个 
*/
