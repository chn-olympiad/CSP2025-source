#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[1005];
bool cmp(int x,int y){
    return x>y;
}
int xx = 1,yy = 1;
void pd(int k){
    if(k == 1){
        return;
    }
    if(xx==n&&yy%2 == 1||xx == 1&&yy%2 == 0){
        yy+=1;
    }
    else{
        if(yy%2 == 1){
            xx+=1;
        }
        else{
            xx-=1;
        }
    }
    pd(k-1);
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n*m;i++){
        cin>>a[i];
    }
    int t = a[1];
    int cnt;

    sort(a+1,a+n*m+1,cmp);
    for(int i = 1;i<=n*m;i++){
        if(a[i] == t){
            cnt = i;
        }
    }
    pd(cnt);
    cout<<yy<<" "<<xx;

    return 0;
}
