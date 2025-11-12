#include<bits/stdc++.h>
using namespace std;
int gs[1100005];
int qz[500005];
int n,k;
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n>>k;
	int i,a;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		qz[i]=qz[i-1]^a;
	}
	gs[0]=1;
	int out=0,ans=0;
	for(i=1;i<=n;i++)
	{
		if(gs[k^qz[i]])//cunzai
		{
			for(out;out<i;out++)
			{
				gs[qz[out]]--;
			}
			ans++;
		}
		gs[qz[i]]++;
	}
	cout<<ans;
	
	return 0;
} 
