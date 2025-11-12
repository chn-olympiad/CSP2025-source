#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		for(int j=3;j<1<<i;j++)
		{
			long long k=0;
			for(int w=1;w<=i-1;w++)
			{
				if((j>>(i-w-1))%2==1) k+=a[w];
			}
			if(k>a[i]*2) ans++;
		}
	}
	cout<<ans;
	
	return 0;
}
//#Shang4Shan3Ruo6Shui4
