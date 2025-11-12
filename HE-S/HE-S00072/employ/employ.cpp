#include<bits/stdc++.h>
using namespace std;
int n,m,s1,c,a;
string p;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		if(s1==0)
		{
			cout<<"无人作出";
			break;
		}else{
			if(s1==1)
			{
				cout<<"均能做出";
				if(i<c)
				{
					break;
				}else{
					a=a+1;
				}
			}
		}
	}
	cout<<a;
	return 0;
}
