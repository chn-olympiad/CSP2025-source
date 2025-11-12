#include<bits/stdc++.h>
using namespace std;
int a;
int b[5000],c[5000];
int sam,Max;
void o(int x){
    c[x]=1;
    Max=0;
    bool boo=1;
    for(int i=1;i<=x;i++){
        if(c[i]==1) Max+=b[i];
    }
    for(int i=1;i<=x;i++){
        if(c[i]==1) {
            if(2*b[i]>=Max) {
            boo=0;
            break;
            }
        }
    }
    if(boo==1) sam++;
    if(x+1<=a) o(x+1);
    c[x]=0;
    if(x+1<=a) o(x+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    sam=0;
    scanf("%d",&a);
    for(int i=1;i<=a;i++) scanf("%d",&b[i]);
    o(1);
    printf("%d",sam);
    return 0;
}
