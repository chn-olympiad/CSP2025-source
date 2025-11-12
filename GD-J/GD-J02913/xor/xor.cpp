#include<bits/stdc++.h>
#define rep(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define ALL(a) (a).begin(),(a).end()
#define fi first
#define se second
using namespace std;
using ll = long long;

const int INF = INT_MAX / 2;
const int N = 5e5 + 5;

int n,k;
int a[N];
int f[N];
bool vis[N];
bool iDontKnow_aaaaaa = true; // is ALL same
bool whoCanSaveMe_aaa = true; // if ALL 0/1

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out", "w",stdout);
    cin >> n >> k;
    rep(i,1,n,1) {
        cin >> a[i];
        if(a[i] != a[1]) iDontKnow_aaaaaa = false;
        if(a[i] != 0 ) whoCanSaveMe_aaa = false;
        if(a[i] != 1 ) whoCanSaveMe_aaa = false;
    }
    if(k == 0) {
        cout << n << endl;
        return 0;
    }
    if(iDontKnow_aaaaaa){
        cout << n << endl;
        return 0;
    }
        int cnt = 0;
        rep(i,1,n,1){
            if(a[i] == 0){
                f[i] = f[i - 1];
                if(f[i] == 3) f[i] = 0;
            }
            else{
                f[i] = f[i - 1] + 1;
                if(f[i] == 4) f[i] = 1;
            }
            if(f[i] == 3) cnt ++;
        }
        int pos = 0;
        per(i,n,1,1) if(f[i] == 3) {pos = i;break;}
        rep(i,pos,n,1){
            if(a[i] == 0) continue;
            if(a[i - 1] == 0 && vis[i - 1] == false) {cnt++; vis[i - 1] = true;continue;}
            if(a[i + 1] == 0 && vis[i + 1] == false) {cnt++; vis[i + 1] = true;continue;}
        }
        cout << cnt <<endl;
        return 0;

}
