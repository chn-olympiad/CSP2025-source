#include<bits/stdc++.h>
using namespace std;
int t,n,i,j,b[100005][3],a[6],c[100005],sum,ans,x,y;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    for(i = 0;i < t;++i){
        cin >> n;
        if(n == 2){
            for(j = 0;j < 2;++j){
                cin >> b[j][0] >> b[j][1] >> b[j][2];
            }
            a[0] = b[0][0] + b[1][1];
            a[1] = b[0][0] + b[1][2];
            a[2] = b[0][1] + b[1][0];
            a[3] = b[0][1] + b[1][2];
            a[4] = b[0][2] + b[1][0];
            a[5] = b[0][2] + b[1][1];
            sort(a,a + 6);
            cout << a[5] << endl;
            memset(a,0,sizeof(a));
            memset(b,0,sizeof(b));
        }
        else{
            for(j = 0;j < n;++j){
                cin >> c[j] >> x >> y;
            }
            sort(c,c + n);
            for(j = n / 2;j < n;++j){
                ans += c[j];
            }
            cout << ans << endl;
            ans = 0;
            memset(c,0,sizeof(c));
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
