#include <iostream>
using namespace std;
int n,t,m[4],ans=0;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d",&t);
    for(int Q=1;Q<=t;Q++){
        ans=0;
        scanf("%d",&n);
        int a[n+5][4]={},b[n+5]={};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                b[i]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=2;j++){
                if(a[i][b[j]]<a[i][j+1]){
                    b[i]=j+1;
                }
            }
        }
        for(int i=1;i<=n;i++){
            ans=ans+a[i][b[i]];
        }
        cout<<ans<<endl;
    }
    return 0;
}
