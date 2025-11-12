#include <bits/stdc++.h>

using namespace std;

int c[5000]={0};
bool book[5000]={0};

void dfs(int c)
{
    return;
}

int main()
{
    int n=0;
    int m=0;
    int ans=1;
    string s;
    vector<int>q;

    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin>>n>>m>>s;

    bool flag=true;
    for(int i=0;i<n;i++)
        if(s[i]=='0')
        {
            flag=false;
            break;
        }

    if(flag)
    {
        for(int i=1;i<=n;i++)
            ans*=i;
        ans=ans%998244353;
    }else{
        dfs(0);
    }


    cout<<ans<<endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
