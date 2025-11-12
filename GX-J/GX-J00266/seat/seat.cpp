#include<bits/stdc++.h>
using namespace std;
int a[105],cnt,p,xx,yy;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    cnt=a[1];
    for(int i=1;i<n*m;i++){
        for(int j=i+1;j<=n*m;j++){
            if(a[i]<a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==cnt){
            p=i;
        }
    }
    xx=(p-1)/n+1;
    if(xx%2==1){
        yy=p-(xx-1)*n;
    }
    else{
        yy=n-(p-(xx-1)*n)+1;
    }
    cout<<xx<<' '<<yy;
    return 0;
}
