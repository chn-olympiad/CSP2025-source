#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int a,int b){
    return a>b;
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
    int r=a[1];
    sort(a+1,a+n*m+1,cmp);
    int cnt=1;
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            break;
        }
        cnt++;
    }
    int h,l;
    if(cnt%n==0){
        l=cnt/n;
    }else{
        l=cnt/n+1;
    }
    int y=cnt%n;
    if(l%2==0){
        h=n-y+1;
    }else{
        h=y;
    }
    if(h==0){
        cout<<l<<" "<<n;
    }else cout<<l<<" "<<h;
    return 0;
}
