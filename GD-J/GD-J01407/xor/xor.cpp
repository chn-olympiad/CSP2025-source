#include<bits/stdc++.h>
using namespace std;
int n,f;
long long ans;
unsigned long long k,x;
unsigned long long a[500001];
bool v[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%ull",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			f=1;
			for(int l=j;l<=j+i-1;l++)
				f&=(!v[l]);
//			cout<<f;
			if(f)
			{
//				cout<<j<<' '<<j+i-1<<endl;
				for(int l=j;l<=j+i-1;l++)
				{
					if(l==j) x=a[l];
					else x^=a[l];
				}
				if(x==k)
				{
					ans++;
					for(int l=j;l<=j+i-1;l++)
						v[l]=1;
//					cout<<j<<' '<<j+i-1<<endl;
				}
			}
		}
	}
	
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
//#Shang4Shan3Ruo6Shui4
