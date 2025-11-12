#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
int mem[1000005];
int ans=0;
/*
4 3
2 1 0 3
    2 1
sum = 3



*/
int dfs(int x)
{
    if(mem[x]!=-1)return mem[x];
    int ret=0;
    for(int i=x;i<=n;i++)
    {
        int sum=0;
        for(int j=i;j<=n;j++)
        {
            sum=(sum^a[j]);
            if(sum==m)
            {
                ret=max(ret,1+dfs(j+1));
//                break;
            }
        }
    }
    mem[x]=ret;
    return ret;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    memset(mem,-1,sizeof(mem));
    mem[n+1]=0;mem[0]=0;
    cout<<dfs(1)<<endl;
    return 0;
}

/*

4 0
2 1 0 3

*/
