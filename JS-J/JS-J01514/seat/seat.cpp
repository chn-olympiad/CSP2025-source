#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=1e4+10;
int a[N],n,m,t;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    t=a[1];
    sort(a+1,a+n*m+1,cmp);
    int cnt=1;
    int flag=1;
    for(int i=1;i<=m;i++){
        if(flag>0){
            for(int j=1;j<=n;j++){
                if(a[cnt]==t){
                    cout<<i<<" "<<j;
                    return 0;
                }
                cnt++;
            }
        }
        else{
             for(int j=n;j>=1;j--){
                if(a[cnt]==t){
                    cout<<i<<" "<<j;
                    return 0;
                }
                cnt++;
            }
        }
        flag=-flag;
    }
}

