#include<bits/stdc++.h>
using namespace std;
int n,m,s[300],ans=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>s[i];
    }
    for(int i=2;i<=n*m;i++)
    {
        if(s[1]<s[i])
        {
            ans++;
        }
    }
    if(ans%n==0&&ans/n!=1)
    {
        cout<<ans/n<<" "<<ans%n+1;
    }
    else if(ans%n!=0)
    {
        cout<<ans/n+1<<" "<<ans%n;
    }
    else if(ans%n==0&&ans/n==1)
    {
        cout<<ans/n<<" "<<ans%n+2;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
