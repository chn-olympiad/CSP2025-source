#include <bits/stdc++.h>
using namespace std;
int seat[100][100];
int a[100];
int n,m;
bool cmp(int a,int b){
    return a>b;
}
void sovle(){
    cin>>n>>m;
    int len = n*m;
    for(int i=1;i<=len;++i){
        cin>>a[i];
    }
    int num = a[1];
    sort(a+1,a+len+1,cmp);
    //for(int i=1;i<=len;++i) cout<<a[i]<<" ";
    cout<<endl;
    int p = 0;
    int cnt = 0;
    for(int j=1;j<=m;++j){
        for(int i=1;i<=n;++i){
            if(j%2==0){
                if(i==1){
                    cnt+=n;
                    p = cnt;
                    seat[i][j] = a[cnt];
                }
                else {
                    seat[i][j] = a[--cnt];
                }
            }
            else {
                if(i==1){
                    cnt = p+1;
                    seat[i][j] = a[cnt];
                }
                else {
                    seat[i][j] = a[++cnt];
                }
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(seat[i][j]==num) {
                cout<<j<<" "<<i;
                break;
            }
        }
    }
    return ;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N = 1;
    while(N--) sovle();
    return 0;
}

