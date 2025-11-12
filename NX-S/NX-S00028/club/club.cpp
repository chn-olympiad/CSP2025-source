#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int t,n,ans,maxi,maxj;
int a1,a2,a3;
int num1,num2,num3;
int rec;
int a[N][4];
int main(){
    ios::sync_with_stdio(false);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i = 0;i < t;i++){
        cin>>n;
        int b[N][3],c[N][3],d[N][3];
        num1 = 0,num2 = 0,num3 = 0,ans = 0;
        for(int j = 0;j < n;j++){
            cin>>a[j][1]>>a[j][2]>>a[j][3];
            //cout<<a[n][1]<<' '<<a[n][2]<<' '<<a[n][3]<<endl;
            /*if(num1 > n/2) a1 = 0;if(num2 > n/2) a2 = 0;if(num3 > n/2) a3 = 0;
            maxi = max(a1,a2);
            maxi = max(maxi,a3);
            if(maxi == a1) num1++;if(maxi == a2) num2++;if(maxi == a3) num3++;
            ans += maxi;*/
        }
        for(int j = 0;j < n;j++){
            b[j][1] = a[j][1];c[j][1] = a[j][2];d[j][1] = a[j][3];
            b[j][2] = j;c[j][2] = j;d[j][2] = j;
        }
        maxi = -1,rec = -1;
        for(int j = 0;j < n/2;j++){
            for(int k = 0;k < n;k++){
                if(b[k][1] != -2){
                    if(maxi > b[k][1]){}
                    if(maxi < b[k][1]){
                        maxi = b[k][1];
                        rec = b[k][2];
                    }
                }
            }
            if(maxi < 0) break;
            maxj = max(b[rec][1],b[rec][2]);
            maxj = max(maxj,b[rec][3]);
            if(maxi == maxj){
                ans+=maxi;
                b[rec][1] = -2,c[rec][1] = -2,d[rec][1] = -2;
            }
        }
        maxi = -1,rec = -1;
        for(int j = 0;j < n/2;j++){
            for(int k = 0;k < n;k++){
                if(c[k][1] != -2){
                    if(maxi > c[k][1]){}
                    if(maxi < c[k][1]){
                        maxi = c[k][1];
                        rec = c[k][2];
                    }
                }
            }
            if(maxi < 0) break;
            maxj = max(c[rec][1],c[rec][2]);
            maxj = max(maxj,c[rec][3]);
            if(maxi == maxj){
                ans+=maxi;
                c[rec][1] = -2,b[rec][1] = -2,d[rec][1] = -2;
            }
        }
        maxi = -1,rec = -1;
        for(int j = 0;j < n/2;j++){
            for(int k = 0;k < n;k++){
                if(d[k][1] != -2){
                    if(maxi > d[k][1]){}
                    if(maxi < d[k][1]){
                        maxi = d[k][1];
                        rec = d[k][2];
                    }
                }
            }
            if(maxi < 0) break;
            maxj = max(d[rec][1],d[rec][2]);
            maxj = max(maxj,d[rec][3]);
            if(maxi == maxj){
                ans+=maxi;
                d[rec][1] = -2,b[rec][1] = -2,c[rec][1] = -2;
            }
        }
        cout<<ans<<endl;
        cout<<c[1][1];
    }
    return 0;
}
