#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

const int N = 1e5 + 10,M = 3 + 10;
int cnt[M];
int a[N],b[N],c[N],mx[N][3];
int max(int a,int b,int c){
    int x = max(a,b);
    return max(x,c);
}
void solved() {
    int n; cin >> n;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i] >> b[i] >> c[i];
        if(max(a[i],b[i],c[i]) == a[i]) mx[i][1] = a[i],mx[i][2] = 1,mx[i][0] = mx[i][1] - max(b[i],c[i]);
        if(max(a[i],b[i],c[i]) == b[i]) mx[i][1] = b[i],mx[i][2] = 2,mx[i][0] = mx[i][1] - max(a[i],c[i]);
        if(max(a[i],b[i],c[i]) == c[i]) mx[i][1] = c[i],mx[i][2] = 3,mx[i][0] = mx[i][1] - max(b[i],a[i]);
    }
    long long sum = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j < n;j ++) {
            if(mx[j][0] < mx[j + 1][0]) swap(mx[j][0],mx[j + 1][0]),swap(mx[j][1],mx[j + 1][1]),swap(mx[j][2],mx[j + 1][2]),swap(a[j],a[j + 1]),swap(b[j],b[j + 1]),swap(c[j],c[j + 1]);
            if(mx[j][0] == mx[j + 1][0]) if(mx[j][1] < mx[j + 1][1]) swap(mx[j][0],mx[j + 1][0]),swap(mx[j][1],mx[j + 1][1]),swap(mx[j][2],mx[j + 1][2]),swap(a[j],a[j + 1]),swap(b[j],b[j + 1]),swap(c[j],c[j + 1]);
        }
    }
    for(int i = 1;i <= n;i ++) {
        if(cnt[mx[i][2]] < n / 2) sum += mx[i][1],cnt[mx[i][2]] ++;
        else {
            if(mx[i][2] == 1) sum += max(b[i],c[i]);
            else if(mx[i][2] == 2) sum += max(a[i],c[i]);
            else if(mx[i][2] == 3) sum += max(b[i],a[i]);
        }
    }
    cout << sum << endl;
    for(int i = 0;i <= 12;i ++) cnt[i] = 0;
}

int main(){
    ios::sync_with_stdio(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t; cin >> t; while(t --)
    solved();
    return 0;
}
