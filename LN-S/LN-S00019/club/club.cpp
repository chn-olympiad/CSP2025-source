#include <bits/stdc++.h>
using namespace std;int b[200][200];
bool cmp(int a,int b){
return a>b;}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;int ans=0;int sum=n/2;int x=0,y=0,z=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%d",&b[i][j]);
            }
        }
        /*int x[35]={0},y[35]={0},z[35]={0};
        for(int i=1;i<=n;i++){
            x[i]=b[i][1];
            y[i]=b[i][2];
            z[i]=b[i][3];
        }
        sort(x+1,x+n+1,cmp);
        sort(y+1,y+n+1,cmp);
        sort(z+1,z+n+1,cmp);
        for(int i=1;i<=sum;i++){
            ans+=x[i]+y[i]+z[i];
        }*/
        for(int i=1;i<=n;i++){
            /*if(b[i][1]>b[i][2]&&b[i][1]>b[i][3]) {
                    x++;
                    if(x>sum){
                        if(b[i][2]>b[i][3]){y++;if(y>sum){z++;if(z<=sum) ans+=b[i][3];}ans+=b[i][2];}
                        else if(b[i][2]<b[i][3]){z++;if(z>sum){y++;if(y<=sum) ans+=b[i][2];}ans+=b[i][3];}
                    }ans+=b[i][1];
            }
            if(b[i][2]>b[i][1]&&b[i][2]>b[i][3]) {
                    y++;
                    if(y>sum){
                        if(b[i][1]>b[i][3]){x++;if(x>sum){z++;if(z<=sum) ans+=b[i][3];}ans+=b[i][1];}
                        else if(b[i][1]<b[i][3]){z++;if(z>sum){x++;if(x<=sum) ans+=b[i][1];}ans+=b[i][3];}
                    }ans+=b[i][2];
            }
            if(b[i][3]>b[i][2]&&b[i][3]>b[i][1]) {
                    z++;
                    if(z>sum){
                        if(b[i][1]>b[i][2]){x++;if(x>sum){y++;if(y<=sum) ans+=b[i][2];}ans+=b[i][1];}
                        else if(b[i][1]<b[i][2]){y++;if(y>sum){x++;if(x<=sum) ans+=b[i][1];}ans+=b[i][2];}
                    }ans+=b[i][3];
            }*/
        ans+=max({b[i][1],b[i][2],b[i][3]});
        }
        cout<<ans<<endl;
        ans=0;
        memset(b,0,sizeof 0);
    }
    return 0;
}
