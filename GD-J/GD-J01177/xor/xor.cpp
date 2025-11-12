#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("xor.in.txt","r",stdin);
	freopen("xor.out.txt","w",stdout);

	int n,k,ans=0;
	cin>>n>>k;
	vector<int> f(n+1);
	for(int i=1;i<=n;i++) cin>>f[i];
	if(k==1)
	{
		for(int i=1;i<=n;i++)
			if(f[i]==1) ans++;
	}
	else if(k==0)
	{
		for(int i=1;i<=n;i++)
			if(f[i]==0) ans++;
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//#Shang4Shan3Ruo6Shui4
