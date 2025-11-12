#include <bits/stdc++.h>
using namespace std;
int n,m,a[1111],num,x=0,y=1,nw=0;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;++i){
        scanf("%d",&a[i]);
    }
    num=a[1];
    for(int i=1;i<=n*m;++i){
        for(int j=1;j<=i;++j){
            if(a[j]<a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
//    for(int i=1;i<=n*m;++i){
//        cout<<a[i]<<" ";
//    }
//    cout<<"\n";
    while(1){
        if((y%2==1&&x==n)||(y%2==0&&x==1)){
            ++y;
        }else{
            if(y%2==1){
                ++x;
            }else{
                --x;
            }
        }
//        cout<<x<<" "<<y<<"\n";
        ++nw;
        if(a[nw]==num){
            printf("%d %d",y,x);
            break;
        }
    }
    return 0;
}
