#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int n,stk[5005];
bool chk(int a[],int len,int nw)
{
    int sum;
    sort(a,a+len);
    for (int i=0;i<len;i++)
        sum+=a[i];
        sum+=nw;
        a[len-1]=max(a[len-1],nw);
    if (sum>2*a[len-1])
    return 1;
    return 0;
}
void dfs(int num,int from,int currn,int chosen[])
{
    if(num==1)
    {
        for(int i=n-currn;i<n;i++)
            if(chk(chosen,currn-1,i))
                ans++;
            return;
    }
    for(int i=n-currn;i<n;i++)
    {
        chosen[sizeof(chosen)/4]=i;
        dfs(num-1,i,currn,chosen);
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>stk[i];
    if (n<3)
    {
        cout<<"0";return 0;
    }
    sort(stk,stk+n);
    if (n==3)
    {
        if((stk[0]+stk[1]+stk[2])>2*stk[2])
            cout<<"1";
        else cout<<"0";
        return 0;
    }
    int chosen[10010];
    memset(chosen,-1,sizeof(chosen));
    for (int i=3;i<n;i++)
        dfs(i,0,i,chosen);
    cout<<ans;
    return 0;
}
