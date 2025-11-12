#include<bits/stdc++.h>
using namespace std;
long long a[10000],b,l,maxx;
int dfs(int h,int t)
{
	if(t>a[l])
	{
		maxx++;
		maxx=maxx%998244353;
	}
	if(h<l)
	{
		for(int i=h+1;i<l;i++)
		{
			dfs(i,t+a[i]); 
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>b;
	for(int i=0;i<b;i++){
		cin>>a[i];
	}
	sort(a+0,a+b);
	for(int i=b-1;i>=2;i--)
	{
		l=i;
		l=dfs(-1,0);
	}
	cout<<maxx;
	return 0;
}