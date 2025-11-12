#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[2025];
bool cmp(int xx,int yy){
    return xx>yy;
}
struct sit{
    int x,y;
}s[2025];
int cnt=1,tg;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    tg=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                s[cnt].x=i;
                s[cnt].y=j;
                cnt++;
            }
        }
        else{
            for(int j=n;j>=1;j--){
                s[cnt].x=i;
                s[cnt].y=i;
                cnt++;
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==tg){
            cout<<s[i].x<<" "<<s[i].y<<'\n';
            return 0;
        }
    }
}
//200pts