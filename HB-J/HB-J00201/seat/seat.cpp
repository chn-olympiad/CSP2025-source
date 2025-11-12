#include<bits/stdc++.h>
using namespace std;
int n,m,b[200],r;
int c;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)scanf("%d",&b[i]);
    r=b[1];
    sort(b+1,b+(n*m)+1,cmp);
    for(int i=1;i<=n*m;i++)if(b[i]==r)c=i;
    int x=c/n,y=c%n;
    if(y==0){
        if(x%2==1){
            printf("%d %d",x,n);
            return 0;
        }
        else {
            printf("%d 1",x);
            return 0;
        }
    }
    x++;
    if(x%2==1){
        printf("%d %d",x,y);
        return 0;
    }
    if(x%2==0){
        printf("%d %d",x,n-y+1);
        return 0;
    }
    return 0;
}
