#include<bits/stdc++.h>
using namespace std;
signed main()
{
	freopen("polygon.in.txt","r",stdin);
	freopen("polygon.out.txt","w",stdout);

	int n;
	cin>>n;
	vector<int> f(n+1);
	for(int i=1;i<=n;i++) cin>>f[i];
	sort(f.begin(),f.end());
	cout<<f[1]+f[n]/2;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//#Shang4Shan3Ruo6Shui4
