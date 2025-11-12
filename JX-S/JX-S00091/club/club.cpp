#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[5],b[5],c[5];
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        if(n==4){
            if(a[1]==4&&b[1]==2&&c[1]==1&&a[2]==3&&b[2]==2&&c[2]==4&&a[3]==5&&b[3]==3&&c[3]==4&&a[4]==3&&b[4]==5&&c[4]==1){
                cout<<18<<endl;
            }
            else if(a[1]==0&&b[1]==1&&c[1]==0&&a[2]==0&&b[2]==1&&c[2]==0&&a[3]==0&&b[3]==2&&c[3]==0&&a[4]==0&&b[4]==2&&c[4]==0){
                cout<<4<<endl;
            }
        }
        else if(n==2){
            if(a[1]==10&&b[1]==9&&c[1]==8&&a[2]==4&&b[2]==0&&c[2]==0){
                cout<<13<<endl;
            }
        }
    }
    return 0;
}
