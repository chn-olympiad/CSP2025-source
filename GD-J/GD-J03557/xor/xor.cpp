#include<bits/stdc++.h>
using namespace std;
long long n,k,a[10000000],s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k) s++;
		else
		{
			long long b=0;
			for(int j=i;j<=n;j++)
			{
				if(a[j]==k) break;
				b^=a[j];
				if(b==k)
				{
					s++,i=j-1;
					break;
				}
			}
		}
	}
	cout<<s;
	return 0;
}
