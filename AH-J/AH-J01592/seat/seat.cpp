#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    int sc=a[1];
    int in;
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==sc){
            in=i;
//            cout<<1<<endl;
            break;
        }
    }
/*    printf("%d\n",in);
    for(int i=1;i<=n*m;i++){
        printf("%d ",a[i]);
    }
    printf("\n");*/
    int c=ceil(in*1.0/n);
    int r;
    printf("%d ",c);
    if(c%2==0){
        r=n;
        for(int i=m*(c-1)+1;i<=m*c;i++){
            if(in==i){
                break;
            }
            r--;
        }
    }else{
        r=1;
        for(int i=m*(c-1)+1;i<=m*c;i++){
            if(in==i){
                break;
            }
            r++;
        }
    }
    printf("%d",r);
    return 0;
}
