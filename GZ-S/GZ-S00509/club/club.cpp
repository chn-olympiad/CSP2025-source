//GZ-S00509 贵州师范大学云岩实验中学 黄瀚德
#include<bits/stdc++.h>
#include<queue>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    for(int q=1;q<=t;q++){
        int n;
        cin >> n;
        int a[10001];
        int b[10001];
        int c[10001];
        int d1=0,d2=0,d3=0;
        int a1,a2,a3;
        int amax =0,bmax=0,cmax=0;
        int am,bm,cm;
        int amin=9999999,bmin=9999999,cmin=9999999;
        for(int e=0;e<n;e++){
            cin >> a[e] >> b[e] >> c[e];
            if(a[e] < amin){
                amin = a[e];
            }
            if(a[e]>amax){
                amax = a[e];
                am = e;
            }
            if(bmax <b[e]){
                bmax = b[e];
                bm = e;
            }
            if(cmax <c[e]){
                cmax = c[e];
                cm = e;
            }if(a[e] > b[e] >c[e],d1<=n/2){
                a1=a1+a[e];
                d1++;
            }else if(b[e] > a[e]>c[e],d2<=n/2){
                a2 = a2+b[e];
                d2++;
            }else if(c[e] > a[e] > b[e],d3<=n/2){
                a3 = a3+c[e];
                d3++;
            }else if(a[e] > b[e] >c[e],d1>n/2){
                if(a[e]>amin){
                    a1=a1-amin +a[e];
                }
            }
            cout << a1+a2+a3;
        }
    }
    fclose("club.in","r"stdin);
    fclose("club.out","w",stdout);
    return 0;
}
