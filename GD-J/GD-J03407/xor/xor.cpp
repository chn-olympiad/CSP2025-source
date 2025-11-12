#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
const int N=5e5+42;
int a[N],b[N],ans;
int vis;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=(a[i]^b[i-1]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=vis+1;j<=i;j++)
		{
			if((b[i]^b[j-1])==m)
			{
				ans++;
				vis=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;

}
 
