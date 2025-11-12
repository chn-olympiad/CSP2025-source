#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>n;
for(int i=1;i<=n;i++){
        int m,ans=0,u,o,p;
        cin>>m;
        int a[m+1][5],b[m+1],c[m+1],d[m+1];
        for(int j=1;j<=m;j++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
                ans+=a[i][1];
                u++;
                b[i]=a[i][1];
                c[i]=-1;
                d[i]=-1;
            }else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
                ans+=a[i][2];
                o++;
                c[i]=a[i][1];
                b[i]=-1;
                d[i]=-1;
            }else{
                ans+=a[i][3];
                p++;
                b[i]=-1;
                c[i]=-1;
                d[i]=a[i][3];
            }
        }while(1){
            if(u<=m/2 && o<=m/2 && p<=m/2)
                break;
            if(u>=m/2){
                int y=999999;
                for(int j=1;j<=u;j++){
                    if(b[i]!=-1)
                        y=min(y,b[i]);
                }
            }if(o>=m/2){
                int y=999999;
                for(int j=1;j<=o;j++){
                    if(c[i]!=-1)
                        y=min(y,c[i]);
                }
            }if(p>=m/2){
                int y=999999;
                for(int j=1;j<=p;j++){
                    if(d[i]!=-1)
                        y=min(y,d[i]);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
