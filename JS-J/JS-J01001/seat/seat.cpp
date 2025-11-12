#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int i,x;
}a[102];
bool cmp(node n1,node n2){
    return n1.x>n2.x;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        int x;
        scanf("%d",&x);
        a[i].i=i;
        a[i].x=x;
    }
    sort(a+1,a+n*m+1,cmp);
    bool f=0,found=0;
    int curi=0,ansc=-1,ansr=-1;
    for(int c=1;c<=m && !found;c++){
        f=!f;
        if(f){
            for(int r=1;r<=n;r++){
                curi++;
                if(a[curi].i==1){
                    ansc=c;
                    ansr=r;
                    found=1;
                    break;
                }
            }
        }else{
            for(int r=n;r>=1;r--){
                curi++;
                if(a[curi].i==1){
                    ansc=c;
                    ansr=r;
                    found=1;
                    break;
                }
            }
        }
        if(found) break;
    }
    printf("%d %d\n",ansc,ansr);
    return 0;
}
