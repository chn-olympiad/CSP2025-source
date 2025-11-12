#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int p[100005];
	int ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	
		for(int i=1;i<=n;i++)
		{
			if(p[i]==0)
			{
				ans++;
			}
		}
		printf("%d",ans);

	return 0;
}

