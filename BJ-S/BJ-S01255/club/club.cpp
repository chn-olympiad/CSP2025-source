#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,ans=0;
        cin>>n;
        int b[5][100005];
        bool an[5][100005]={false};
        int x=0,y=0,z=0;
        int w[50005],m[50005],q[50005];
        for(int j=1;j<=n;j++){
            int a[4];
            cin>>a[1]>>a[2]>>a[3];
            b[1][j]=a[1];
            b[2][j]=a[2];
            b[3][j]=a[3];
            sort(a+1,a+4);
            for(int k=1;k<=3;k++){
                if(b[k][j]==a[3]){
                    if(k==1&&x<n/2){
                        x++;
                        ans+=a[3];
                        k=4;
                    }else if(k==2&&y<n/2){
                        y++;
                        k=4;
                        ans+=a[3];
                    }else if(k==3&&z<n/2){
                        z++;
                        ans+=a[3];
                        k=4;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}
