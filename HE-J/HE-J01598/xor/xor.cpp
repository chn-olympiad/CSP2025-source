#include<bits/stdc++.h>
using namespace std;

int solve(int x,int y,int z,int a[]);   //r,l,n

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int ans=0;
    for(int r=1;r<n;r++)
    {
        for(int l=r;l<r;l++)
        {
            if(solve(r,l,n,a)==k) ans++;
        }
    }
    cout<<ans;
    return 0;
}

int solve(int x,int y,int z,int a[])
{
    if(x==y && y==z) return a[y]^a[x];
    else
		return a[x-1]^solve(x,y,z,a);
}
