#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define pb push_back
#define fi first
#define se second
#define all(a) a.begin(),a.end()
int t,n,a[10000000],b[1000000],c[1000000],d[10000000],f[1000000],ans,x,y,z;
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        if(n==2){
                cin>>a[1]>>a[2]>>a[3];
                cin>>b[1]>>b[2]>>b[3];
                for(int i=1;i<=3;i++){
                    for(int j=1;j<=3;j++){
                        if(i!=j) ans=max(ans,a[i]+b[j]);
                    }
                }
                cout<<ans<<endl;
        }
        else if(n==4){
                cin>>a[1]>>a[2]>>a[3];
                cin>>b[1]>>b[2]>>b[3];
                cin>>c[1]>>c[2]>>c[3];
                cin>>d[1]>>d[2]>>d[3];
                for(int i=1;i<=3;i++){
                    for(int j=1;j<=3;j++){
                        for(int l=1;l<=3;l++){
                            for(int k=1;k<=3;k++){
                                f[i]++;
                                f[j]++;
                                f[l]++;
                                f[k]++;
                                    if(f[1]<=2||f[2]<=2||f[3]<=2){
                                        ans=max(ans,a[i]+b[j]+c[l]+d[k]);
                                    }
                                f[1]=0;f[2]=0;f[3]=0;
                            }
                        }
                    }
                }
            cout<<ans<<endl;
        }
        else{
            cin>>x>>y>>z;
            if(y==0&&z==0){
                a[1]=x;
                for(int i=2;i<=n;i++){
                    cin>>a[i]>>y>>z;
                }
                sort(a+1,a+n+1);
                for(int i=1;i<=n/2;i++){
                    ans+=a[i];
                }
                cout<<ans<<endl;
            }
        }

    }
    return 0;
}
