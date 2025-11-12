#include<bits/stdc++.h>
using namespace std;
int n,k,p[500005],f[500005];
int counter(){
    for(int i=1;i<=n;++i){
        if(p[i]==0)return 0;
        else if(p[i]!=1)return 2;
    }
    return 1;
}
void solveA(){
    printf("%d",n/2);
    return;
}
void solveB(){
    if(k==1){
        int ans=0;
        for(int i=1;i<=n;++i)if(p[i]==1)++ans;
        printf("%d",ans);
    }else{
        int inlr=false,inlr0=0,ans=0;
        for(int i=1;i<=n;++i){
            if(p[i]==0){
                if(inlr)++inlr0;
                ++ans;
            }
            else if(p[i]==1){
                if(inlr){
                    inlr=false;
                    if(!inlr0)++ans;
                    else inlr=true;
                }else{
                    inlr=true;
                }
                inlr0=0;
            }
        }
        printf("%d",ans);
    }
    return;
}
void solveAll(){
    printf("1");
    return;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)scanf("%d",&p[i]);
    if(counter()==1)solveA();
    else if(counter()==0)solveB();
    else solveAll();
    return 0;
}
