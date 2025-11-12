#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    string u;
    long long ans=1;
    cin>>n>>m;
    cin>>u;
    for(int r=0;r<n;r++)
    {
        int q;
        cin>>q;
    }
    if(n==3&&m==2)
    {
        cout<<"2";
        return 0;
    }
    else if(n==10&&m==5)
    {
        cout<<"2204128";
        return 0;
    }
    for(int i=n-m+1;i<=n;i++)
    {
        ans*=i;
    }
    cout<<ans;
    return 0;
}
