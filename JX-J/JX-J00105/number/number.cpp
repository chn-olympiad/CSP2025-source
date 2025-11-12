#include<bits/stdc++.h>
using namespace std;
int tong[12];
int main()
{   freopen("r","number.in",stdin);
    freopen("w","number.out",stdout);
    string a;
    cin>>a;
    int cnt=0;
    for(int i=0;i<a.size();i++)
    {
		 if(a[i]>='0'&&a[i]<='9')
		 {
			 cnt++;
			 tong[a[i]-'0']++;
		 }
	}
	for(int i=9;i>=0;i--)
	{
		if(tong[i]!=0)
		{
			for(int j=1;j<=tong[i];j++)
			{
				cout<<i;
			}
		}
	}
    
    return 0;
}
