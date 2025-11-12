#include<bits/stdc++.h>
using namespace std;
struct cc{
    int id;
    int data;
}a[1005];
bool cmp(cc x,cc y){
    return x.data>y.data;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i].data);
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int in=0;
    for(int i=1;i<=n*m;i++){
        if(a[i].id==1){
            in=i;
        }
    }
    int t=in/n;
    if(t*n<in){
        cout<<t+1<<" ";
        int c=in-t*n;
        if((t+1)%2==1){
            cout<<c;
        }else{
            cout<<n-c+1;
        }
    }else{
        cout<<t<<" "<<n;
    }
return 0;
}
