#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    for(int ii = 0;ii<t;ii++){
        int n,s = 0;
        int d[5005][4],e[20005],g[3];
        cin >> n;
        int nn = n/2,nnn = 0;
        for(int i = 0;i<n;i++){
            cin >> d[i][0] >> d[i][1] >> d[i][2];
            int a = d[i][0];
            int b = d[i][1];
            int c = d[i][2];
            d[i][3] = max(a,b);
            d[i][3] = max(c,d[i][3]);
            int dd = d[i][3];
            if(a==b&&a==dd || b==c&&b==dd || a==c&&c==dd) nnn++;
            s+=d[i][3];
            int k = 0;
            for(int j = 0;j<3;j++){
                int h = d[i][3]-d[i][j];
                if(h==0 && k==0){
                    g[j]++;
                    k = 1;
                }
                else e[h]++;
            }
        }
        int f = max(g[0],g[1]);
        f = max(g[2],f)-nn-nnn;
        for(int i = 1;f>0;i++){
            if(e[i]>=f){
                s-=i*f;
                f = 0;
                break;
            }s-=e[i]*i;
            f-=e[i];
        }
        cout << s << endl;
        s = 0;
        g[0] = g[1] = g[2] = 0;
    }
    return 0;
}