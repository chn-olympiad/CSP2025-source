#include<bits/stdc++.h>

using namespace std;

int n,k,a[500010],ans,xor_[500010];
int w=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		xor_[i]=a[i] xor xor_[i-1];
		for(int j=w; j<=i; j++)
		{
			if((xor_[i] xor xor_[j-1])==k)
			{
				ans++;
				w=i+1;
				break;
			}
		}
	} 
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
