#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[105],sc,w;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    sc=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==sc){
            w=i;
            break;
        }
    }
    int x=-1,y=-1;
    for(int i=1;i<=m;i++){
        if(x!=-1&&y!=-1){
            break;
        }
        if(n*(i-1)+1<=w&&w<=n*i){
            x=i;
            if(i&1){
                for(int j=n*(i-1)+1;j<=n*i;j++){
                    if(a[j]==a[w]){
                        y=j-n*(i-1);
                    }
                }
            }
            else{
                for(int j=n*i;j>=n*(i-1)+1;j--){
                    if(a[j]==a[w]){
                        y=n*i-j+1;
                    }
                }
            }
        }
    }
    cout<<x<<' '<<y;
    return 0;
}