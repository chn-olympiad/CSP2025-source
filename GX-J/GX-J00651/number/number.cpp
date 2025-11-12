#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int n,ans=0;;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n;
    for(int i=1;i<n;i++)
    if(i<n)
    ans++;
    cout<<ans;
	return 0;
}
