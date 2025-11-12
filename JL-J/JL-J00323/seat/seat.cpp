#include<bits/stdc++.h>
using namespace std;
int n,m,s[11][11];
pair<int,int>a[101];
bool cmp(pair<int,int> x,pair<int,int> y){
    return x.first>y.first;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        int x;
        scanf("%d",&x);
        a[i].first=x;
        a[i].second=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int x=0,y=1,pos=1,tot=0;
    while(true){
        if(pos==1&&x==n){
            tot++;
            pos*=-1;
            y++;
        }else if(pos==-1&&x==1){
            tot++;
            pos*=-1;
            y++;
        }else{
            tot++;
            x+=pos;
        }
        if(a[tot].second==1){
            printf("%d %d\n",y,x);
            break;
        }
    }
}
