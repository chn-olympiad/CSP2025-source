#include<bits/stdc++.h>
using namespace std;
int num[1000],cfnum[1000];
int ave(int a,int b)
{
    if(a==0&&b!=0) return b;
    if(b==0&&a!=0) return a;
    if(a==0&&b==0) return 0;
    if(a%2==b%2) return ave(a/2,b/2)*2;
    else return ave(a/2,b/2)*2+1;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
        cfnum[i]=ave(num[i],cfnum[i-1]);
    }
    int l=1,ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=l;j<=i;j++)
        {
            if(j==i&&num[i]==k)
            {
                l++;
                ans++;
               break;
            }
            if(ave(cfnum[i],cfnum[j-1])==k)
            {
                l=i+1;
                ans++;
                break;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
