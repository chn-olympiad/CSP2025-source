#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
        int n,m;
        cin>>n>>m;
        string a;
        cin>>a;
        int c[1000000]={0};
        int mi=0;
        for(int i=1;i<=n;i++){
            cin>>c[i];
            if(c[i]==0)
                mi++;
        }
        unsigned long long ans=1;
        if(n-mi>=m){
        for(int i=2;i<=n;i++)
        {
            ans=ans*i;
            ans=ans%998244353;
        }
        cout<<ans;
        }
        else
        cout<<0;
        fclose(stdin);
        fclose(stdout);
        return 0;
}
