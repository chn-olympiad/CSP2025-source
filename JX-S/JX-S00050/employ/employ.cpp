#include <iostream>
using namespace std;
int n,m,s,c[505],z[505],cc[505],nd[505],r,ans,ans1;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ans=0;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        z[c[i]]=z[c[i]]+1;
    }
    for(int i=1;i<=n;i++){
        nd[i]=s%(10^(n-i));
        s=s-s%(10^(n-i))*(10^(n-i));
    }
    for(int i=1;i<=n;i++){
        if(nd[i]==1){
            r=r+1;
        }
    }
    if(r<m){
        cout<<"0"<<endl;
    }else if(r==m){
        ans=1;
        for(int i=1;i<=n;i++){
            if(nd[i]==1){
                ans=ans*z[i];
            }
        }
        cout<<ans<<endl;
    }else if(r>m){
        ans=1;
        `for(int i=1;i<=n;i++){
            if(nd[i]==1){
                r=r+1;
                cc[r]=z[i];
            }
        }
        for(int i=1;i<=r-m;i++){
            for(int j=i;j<=m+i;j++){
                ans=ans*cc[j];
            }
            ans1=ans1+ans;
            ans=1;
        }
        cout<<ans1<<endl;
    }
    return 0;
}
