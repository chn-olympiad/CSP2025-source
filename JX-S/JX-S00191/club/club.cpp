#include<bits/stdc++.h>
using namespace std;
int t,tj[3];
long long n,ans,z,a;
int ls[100005][3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans = z = 0;
        cin>>n;
        if(n==2){
            for(int i=1;i<=n;i++)
                cin>>ls[i][1]>>ls[i][2]>>ls[i][3];
            z = max(ls[1][1]+ls[2][2],ls[1][1]+ls[2][3]);
            ans = max(z,ans);
            z = max(ls[1][2]+ls[2][1],ls[1][2]+ls[2][3]);
            ans = max(ans,z);
            z = max(ls[1][3]+ls[2][1],ls[1][3]+ls[2][2]);
            ans = max(z,ans);
            cout<<ans<<"\n";
        }
        else if(n==4){
            for(int i=1;i<=n;i++)
                cin>>ls[i][1]>>ls[i][2]>>ls[i][3];
            a = ls[1][1]+ls[2][2]+ls[3][3];
            z = max(ls[4][1],max(ls[4][2],ls[4][3]))+a;//1231 && 1232 && 1233
            ans = max(ans,z);
            a = ls[1][1]+ls[2][3]+ls[3][2];
            z = max(ls[4][1],max(ls[4][2],ls[4][3]))+a;//1321 && 1322 && 1323
            ans = max(ans,z);
            a = ls[1][2]+ls[2][1]+ls[3][3];
            z = max(ls[4][1],max(ls[4][2],ls[4][3]))+a;//2131 && 2132 && 2133
            ans = max(ans,z);
            a = ls[1][2]+ls[2][3]+ls[3][1];
            z = max(ls[4][1],max(ls[4][2],ls[4][3]))+a;//2311 && 2312 && 2313
            ans = max(ans,z);
            a = ls[1][3]+ls[2][1]+ls[3][2];
            z = max(ls[4][1],max(ls[4][2],ls[4][3]))+a;//3121 && 3122 && 3123
            ans = max(ans,z);
            a = ls[1][3]+ls[2][2]+ls[3][1];
            z = max(ls[4][1],max(ls[4][2],ls[4][3]))+a;//3211 && 3212 && 3213
            ans = max(ans,z);
            z = max(ls[1][1]+ls[2][1]+ls[3][2]+ls[4][2],max(ls[1][1]+ls[2][1]+ls[3][3]+ls[4][3],ls[1][2]+ls[2][2]+ls[3][3]+ls[4][3]));
            ans = max(ans,z);
            z = max(ls[1][2]+ls[2][2]+ls[3][1]+ls[4][1],max(ls[1][3]+ls[2][3]+ls[3][1]+ls[4][1],ls[1][3]+ls[2][3]+ls[3][2]+ls[4][2]));
            ans = max(ans,z);
            z = max(ls[1][1]+ls[3][1]+ls[2][2]+ls[4][2],max(ls[1][1]+ls[3][1]+ls[2][3]+ls[4][3],ls[1][2]+ls[3][2]+ls[2][3]+ls[4][3]));
            ans = max(ans,z);
            z = max(ls[1][2]+ls[3][2]+ls[2][1]+ls[4][1],max(ls[1][3]+ls[3][3]+ls[2][1]+ls[4][1],ls[1][3]+ls[3][3]+ls[2][2]+ls[4][2]));
            ans = max(ans,z);
            z = max(ls[2][1]+ls[3][1]+ls[1][2]+ls[4][2],max(ls[2][1]+ls[3][1]+ls[1][3]+ls[4][3],ls[2][2]+ls[3][2]+ls[1][3]+ls[4][3]));
            ans = max(ans,z);
            z = max(ls[2][2]+ls[3][2]+ls[1][1]+ls[4][1],max(ls[2][3]+ls[3][3]+ls[1][1]+ls[4][1],ls[2][3]+ls[3][3]+ls[1][2]+ls[4][2]));
            ans = max(ans,z);
            cout<<ans<<"\n";
        }
        else{
            for(int i=1;i<=n;i++){
                int maxq = 0;
                for(int j=0;j<3;j++){
                    maxq = max(maxq,ls[i][j]);
                }
                ans += maxq;
            }
            cout<<ans<<"\n";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
