#include<bits/stdc++.h>
using namespace std;
const int N=5*100000+5;
int a[N],n,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int lastend=0,ret=0;
	for(int start=1;start<=n;start++)
	{
		int tmp=0;
		for(int cur=start;cur<=n;cur++)
		{
			tmp^=a[cur];
			if(tmp==k)
			{
				if(start>lastend)
				{
					ret++,lastend=cur;
				}
				else
				{
					if(cur<lastend)
					{
						lastend=cur;
					}
				}
				break;
			}
		}
	}
	cout<<ret<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}