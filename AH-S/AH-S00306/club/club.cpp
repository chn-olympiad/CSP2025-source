#include<bits/stdc++.h>
using namespace std;
int t,n,k,f[500010][5],cnt;
struct person{
    int a,b,c,mx,mn,md;
}mem[100010];
int flag1,flag2,ka,kb,kc;
int mid(person z){
    return z.a+z.b+z.c-z.mx-z.mn;
}
bool cmp(person x,person y){
    return x.mx-x.md>y.mx-y.md;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&mem[i].a,&mem[i].b,&mem[i].c);
            mem[i].mx=max(mem[i].a,max(mem[i].b,mem[i].c));
            mem[i].mn=min(mem[i].a,min(mem[i].b,mem[i].c));
            mem[i].md=mid(mem[i]);
        }
        ka=kb=kc=0;
        cnt=0;
        sort(mem+1,mem+1+n,cmp);
        for(int i=1;i<=n;i++){
            if(mem[i].mx==mem[i].a){
                if(ka>=n/2){
                    cnt+=mem[i].md;
                    if(mem[i].md==mem[i].b)
                        kb++;
                    else
                        kc++;
                }
                else{
                    ka++;
                    cnt+=mem[i].mx;
                }
            }
            else if(mem[i].mx==mem[i].b){
                if(kb>=n/2){
                    cnt+=mem[i].md;
                    if(mem[i].md==mem[i].a)
                        ka++;
                    else
                        kc++;
                }
                else{
                    kb++;
                    cnt+=mem[i].mx;
                }
            }
            else{
                if(kc>=n/2){
                    cnt+=mem[i].md;
                    if(mem[i].md==mem[i].a)
                        ka++;
                    else
                        kb++;
                }
                else{
                    kc++;
                    cnt+=mem[i].mx;
                }
            }
        }

        printf("%d\n",cnt);
    }
    return 0;
}
