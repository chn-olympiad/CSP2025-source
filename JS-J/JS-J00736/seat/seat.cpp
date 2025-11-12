#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+5;
int a[maxn];
int s[20][20];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int cnt=1,r=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            s[i][j]=a[cnt];
            ++cnt;
        }
        ++i;
        if(i>m){
            break;
        }
        for(int j=n;j>=1;j--){
            s[i][j]=a[cnt];
            ++cnt;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[i][j]==r){
                cout<<i<<" "<<j;
                break;
            }
        }
    }
    return 0;
}
