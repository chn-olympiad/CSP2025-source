#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    int cnt=n*m;
    for(int i=1;i<=cnt;++i){
        scanf("%d",&a[i]);
    }
    int s=a[1],ct;
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;++i){
        if(a[i]==s){
            ct=i;
        }
    }
    int x=ct/n,y=ct%n;
    if(y==0){
        if(x%2==0){
            printf("%d %d",x,1);
        }else{
            printf("%d %d",x,n);
        }
    }else{
        if(x%2==0){
            printf("%d %d",x+1,y);
        }else{
            printf("%d %d",x+1,n+1-y);
        }
    }
    return 0;
}
