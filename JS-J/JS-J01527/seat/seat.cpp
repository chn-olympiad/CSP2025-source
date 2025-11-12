#include<bits/stdc++.h>
using namespace std;
struct node{
    int mark,bzz;
}a[110];
int n,m;
node s[20][20];
bool cmp(node x,node y){
    return x.mark>=y.mark;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].mark;
        a[i].bzz=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                s[i][j]=a[(i-1)*n+j];
            }
        }else{
            for(int j=n;j>=1;j--){
                s[i][j]=a[(i-1)*n+n-j+1];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j].bzz==1){
                cout<<i<<' '<<j;
            }
        }
    }
 return 0;
}
