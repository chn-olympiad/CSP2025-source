#include<cstdio>
#include<iostream>
using namespace std;

int s[500005],check;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int f;
    cin>>f;
    int cnt=(f==1);
    s[1]=f;
    for(int i=2;i<=n;i++)
    {
        int a;
        cin>>a;
        cnt+=(a==1);
        s[i]=s[i-1]^a;
    }
    if(cnt==n)
    {
        cout<<n/2;
        return 0;
    }
    cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(i<check)continue;
        for(int j=i;j<=n;j++)
        {
            int sum=s[j]^s[i-1];
            if(sum==k&&check<j){
                cnt++;
                check=j;
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}
