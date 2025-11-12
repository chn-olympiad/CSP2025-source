#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct Node{
    int x,y,z,mx;
}a[N];
int t,n,xc,yc,zc,ans,x[N],y[N],z[N];
void init(){
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    memset(z,0,sizeof(z));
    xc = yc = zc = 0;
    ans = 0;
}
bool cmp(int i,int j){
    return i > j;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        init();
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i].x >> a[i].y >> a[i].z;
            a[i].mx = max({a[i].x,a[i].y,a[i].z});
            if(a[i].mx == a[i].x){
                x[xc++] = a[i].x;
            }
            else if(a[i].mx == a[i].y){
                y[yc++] = a[i].y;
            }
            else if(a[i].mx == a[i].z){
                z[zc++] = a[i].z;
            }
        }
        sort(x,x + xc,cmp);
        sort(y,y + yc,cmp);
        sort(z,z + zc,cmp);
        for(int i = 0;i < xc;i++){
            if(i <= n / 2){
                ans += x[i];
            }
        }
        for(int i = 0;i < yc;i++){
            if(i <= n / 2){
                ans += y[i];
            }
        }
        for(int i = 0;i < zc;i++){
            if(i <= n / 2){
                ans += z[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
