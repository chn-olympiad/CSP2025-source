#include<bits/stdc++.h>
using namespace std;
string a;
int b[20],c,d,e,f,g,h;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a;
	for(int i=0;i<int(a.size());i++)
	{
		if('0'<=a[i] && a[i]<='9')
		{
			int u=a[i]-'0';
			b[u]++;
		}
	}
	c=1;
	for(int i=9;i>=0;i--)
	{
		if(9>=i && i>=1 && b[i]>0)
		{
			c=0;
			while(b[i])
			{
				b[i]--;
				cout<<i;
			}
		}
		if(i==0)
		{
			if(b[i]>0)
			{
				if(c==1)
				{
					cout<<"0";
				}
				else
				{
					while(b[i])
					{
						b[i]--;
						cout<<i;
					}
				}
			}
		}
	}

	return 0;
}
