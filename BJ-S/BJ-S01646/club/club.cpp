#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][3];
int b[N][2];
int c[3];
int main(){
    freopen("club1.in","r",stdin);
    freopen("club1.out","w",stdout);
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        for(int j=1;j<=3;j++){
            for(int i=1;i<=n;i++){
                if(b[i][1]<a[i][j]){
                    b[i][2]=j;
                    b[i][1]=a[i][j];
                }
                if(b[i][2]==1)c[1]++;
                if(b[i][2]==2)c[2]++;
                if(b[i][2]==3)c[3]++;
            }
        }
            if(a[1][1]==0){
                b[1][2]=0;
                b[2][2]=0;
            }
        int s=0;
        for(int i=1;i<=n;i++){
            s=s+b[i][1];
        }
        cout<<s<<endl;
        for(int i=1;i<=n;i++){
            b[i][1]=0;
        }
    }
    return 0;
}
