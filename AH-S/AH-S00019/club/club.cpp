#include<bits/stdc++.h>
using namespace std;
int t,n,s;
int a[10001][4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
		cin>>n;
		s=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			s+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		cout<<s;
	}
	return 0;
}
