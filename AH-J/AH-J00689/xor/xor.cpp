#include<bits/stdc++.h>
using namespace std;
int a[500005];
int s[500005];
struct Node{
    int x,y;
};
Node b[25000005];
int in=0;
bool cmp(Node m,Node n){
    if(m.y!=n.y){
        return m.y<n.y;
    }else{
        return m.x<n.x;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=(s[i-1]^a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int x=1,y=x+i-1;y<=n;x++,y++){
            if((s[y]^s[x-1])==k){
                Node t;
                t.x=x;
                t.y=y;
                b[++in]=t;
            }
        }
    }
    sort(b+1,b+1+in,cmp);
    int num=1,last=b[1].y;
    for(int i=2;i<=in;i++){
        if( b[i].x >last ){
            num++;
            last= b[i].y;
        }
    }
    cout<<num;
    return 0;
}
