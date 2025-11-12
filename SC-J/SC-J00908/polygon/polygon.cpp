#include<bits/stdc++.h>
using namespace std;
int num=0,n;
vector<int>A;
bool PD(int max_q,int q)
{
    if(max_q*2<q) return true;
    return false;
}
void dfs(int x,int k,int m,int q,int max_q)
{
    if(k==m && PD(max_q,q))
    {
        num++;
        return;
    }
    for(int i=x;i<n;i++)
    {
        int a=max_q;
        q+=A[i];
        max_q=max(max_q,A[i]);
        dfs(i+1,k+1,m,q,max_q);
        max_q=a;
        q-=A[i];
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    A.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    if(n<3)
    {
        cout<<0;
        return 0;
    }
    sort(A.begin(),A.end());
    for(int i=3;i<=n;i++)
    {
        for(int j=0;j<n-i+1;j++)
        {
            dfs(j,0,i,0,0);
        }
    }
    cout<<num;
    return 0;
}