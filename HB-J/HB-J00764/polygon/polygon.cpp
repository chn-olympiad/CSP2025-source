#include<bits/stdc++.h>
using namespace std;
int b[100000];
int main()
{
	
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    sort(b+1,b+n+1);
    if(n==3)
    {
		if(b[1]+b[2]>b[3])
		{
			cout<<1;
		}	
		else
		{
			cout<<0;
		}
	}
}
