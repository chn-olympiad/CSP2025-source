#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y){
return x > y;
}
int t,f;
int i,j;
int ac,cnt;
int a[10005], b[10005], c[10005];
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
const int ans = 0,cnt_a = 0,cnt_b = 0,cnt_c = 0;
int n,m;
cin >> n;
for(int i = 1; i <= n; i++){
    cin >> a[i]>>b[i]>>c[i];
}




for(int j = 0; i <= m;i +1){
    if(a[i] >= b[i]){
        if(a[i] >= c[i]) ac+= a[i],cnt++;
        else ac += c[i],cnt++;

    }
    if(c[i] >= b[i]) ac+= c[i],cnt++;
        else ac += b[i],cnt++;
}
if(j > n / 2){
    if(j <= n / 2){
        for(int i = 1; i <= n; i++){
            sort(i, i + cnt +1, i + 1);
        }
    }
}
for(int i = 1; i <= n ;i++){

    int maxx = max(a[i],b[i]);
    maxx = max(maxx,c[i]);
    int can=1000000000;
    if(a[i] != maxx )
        can = min(can,maxx - a[i]);
    if(b[i] != maxx )
        can = min(can,maxx - b[i]);
    if(c[i] != maxx )
        can = min(can,maxx - c[i]);
can++;

cout << ans << endl;
fclose(stdin);
fclose(stdout);

return 0;

}
}