#include<bits/stdc++.h>
using namespace std;
int n;
int  a[60001]={0};
bool bj[60001]={false}; long long ans=0;
void dfs(long long hei,long long fa,long long zh)
{
    if(hei>2)
    {
        if(zh>a[fa]){
            ans++;
        }
            ans=ans%998244353;
    }
    for(int i=fa+1;i<=n;i++)
    {
            dfs(hei+1,i,zh+a[fa]);
    }
    return;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
        sort(a+1,a+1+n);
    dfs(1,0,0);
    cout<<ans%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
