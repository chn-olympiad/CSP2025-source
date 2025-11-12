#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        bool isA=true;
        int isaa[n];
        bool isB=true;
        int isbb[n];
        int bum[3][n];
        int renm[n][3];
        for(int i=1;i<=n;i++){
            int o, t, s;
            cin >> o >> t >> s;
            if(s!=0) isB=false;
            if(s!=0 && t!=0) isA=false;
            isaa[i]=o;
            bum[1][i]=o;
            bum[2][i]=t;
            bum[3][i]=s;
            renm[i][1]=o;
            renm[i][2]=t;
            renm[i][3]=s;
        }
        int ans=0;
        if(n==2){
            if(renm[1][1]+renm[2][2]>ans) ans=renm[1][1]+renm[2][2];
            if(renm[1][1]+renm[2][3]>ans) ans=renm[1][1]+renm[2][3];
            if(renm[1][2]+renm[2][3]>ans) ans=renm[1][2]+renm[2][3];
            if(renm[1][2]+renm[2][1]>ans) ans=renm[1][2]+renm[2][1];
            if(renm[1][3]+renm[2][1]>ans) ans=renm[1][3]+renm[2][1];
            if(renm[1][3]+renm[2][2]>ans) ans=renm[1][3]+renm[2][2];
            cout << ans << endl;
            continue;
        }
        if(isA){
            sort(isaa+1, isaa+n+1);
            for(int i=n;i>n/2;i--){
                ans+=isaa[i];
            }
            cout << ans << endl;
            continue;
        }

    }
    return 0;
}
