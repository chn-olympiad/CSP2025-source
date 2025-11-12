#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,a[500005],ans=0;
int main()
{
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++) cin>>a[i];
for(int l=1;l<=n;l++)
{
	int c=-1,wer=0;
	for(int r=l;r<=n;r++)
	{
		if(c<0&&l!=r)c=a[l]^a[r];
		else c=c^a[r];
		int d=c;
		while(d>0)
		{
			wer+=d%2;
			d=d>>1;
		}
		if(wer==k)
		{
			ans++;
			l=r+1;
			break;
		} else 
		if(wer>k) break;
	}
}
cout<<ans+1;
return 0;
}
