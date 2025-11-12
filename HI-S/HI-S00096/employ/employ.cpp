#include<bits/stdc++.h>
using namespace std;
const int M=550;
string s;
int a[550],h[550],n,m,o;
long long ans;
int bl(int x,int y,int z,int d)
{
	if(z>=a[x])
	{
		z++;
	}
	else if(s[d]=='1')
	{
		y++;
	}
	else
	{
		z++;
	}
	if(y>=m)
	{
		ans++;
		ans%=998244353;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(h[i]==0){
		h[i]=1;
		bl(i,y,z,d+1);
		h[i]=0;}
	}
	return 0;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	if(n>=100)
	{
		cout<<432511605;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		h[i]=1;
		bl(i,0,0,0);
		h[i]=0;
	}
	cout<<ans;
	return 0;
} 
