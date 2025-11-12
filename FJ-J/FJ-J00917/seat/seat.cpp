#include<bits/stdc++.h>
using namespace std;
int s[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a=1,b=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i];
		if(s[1]>=s[i]) 
		{
			cout<<a<<" "<<b;
		}
		else if(s[1]<s[i])
		{
			a++;
			if(a>n)
			{
				b++;
			}
		}

    }
    cout<<a<<" "<<b;

	return 0;
}
