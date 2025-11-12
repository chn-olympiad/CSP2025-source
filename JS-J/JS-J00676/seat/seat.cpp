#include <bits/stdc++.h>
using namespace std;
int n,m,cnt=0;
int a[200];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cnt++;
            cin>>a[cnt];
        }
    }
    int R=a[1];
    sort(a+1,a+cnt+1,cmp);
    int RR;
    for(int i=1;i<=cnt;i++){
        if(a[i]==R){
            RR=i;
            break;
        }
    }
    int r=(RR-1)/n+1;
    int c;
    if(r%2==1){
        c=RR-(r-1)*n;
    }
    else{
        c=m-(RR-(r-1)*n)+1;
    }
    cout<<r<<" "<<c;
    return 0;
}
