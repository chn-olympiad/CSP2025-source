#include<bits/stdc++.h>
using namespace std;
struct node{
    int value,cnt;
}a[105];
bool cmp(node x,node y){
    return x.value>y.value;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,zw[11][11],b=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].value;
        a[i].cnt=i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==0){
            for(int j=n;j>=1;j--){
                zw[j][i]=a[b].cnt;
                b++;
            }
        }
        else if(i%2!=0){
            for(int j=1;j<=n;j++){
                zw[j][i]=a[b].cnt;
                b++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(zw[i][j]==1){
                cout<<m<<" "<<n<<endl;
            }
        }
    }
    return 0;
}
