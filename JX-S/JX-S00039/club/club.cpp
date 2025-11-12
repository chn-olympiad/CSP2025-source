#include<bits/stdc++.h>
using namespace std;
struct member{
    int a1,a2,a3,a4;
};
member mem[100005];
bool cmp(int a,int b){
    return mem[a].a4>mem[b].a4;
}
int m1[100005],m2[100005],m3[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    int n;int n1,n2,n3;int sum;
    for(int k=0;k<t;k++){
        scanf("%d",&n);
        n1=0;n2=0;n3=0;sum=0;
        for(int i=0;i<n;i++){
            scanf("%d %d %d",&mem[i].a1,&mem[i].a2,&mem[i].a3);
            if(mem[i].a1>mem[i].a2){
                if(mem[i].a1>mem[i].a3){
                    m1[n1++]=i;
                    mem[i].a4=mem[i].a1-max(mem[i].a2,mem[i].a3);
                }
                else{
                    m3[n3++]=i;
                    mem[i].a4=mem[i].a3-max(mem[i].a2,mem[i].a1);
                }
            }
            else{
                if(mem[i].a2>mem[i].a3){
                    m2[n2++]=i;
                    mem[i].a4=mem[i].a2-max(mem[i].a1,mem[i].a3);
                }
                else{
                    m3[n3++]=i;
                    mem[i].a4=mem[i].a3-max(mem[i].a2,mem[i].a1);
                }
            }
        }
        if(n1>n/2){
            sort(m1,m1+n1,cmp);
            for(int i=n1-1;i>n/2-1;i--){
                if((mem[m1[i]].a2>mem[m1[i]].a3)&&(n2+1<=n/2)){
                    m2[n2++]=m1[i];
                    n1--;
                }
                else{
                    m3[n3++]=m1[i];
                    n1--;
                }
            }
        }
        if(n2>n/2){
            sort(m2,m2+n2,cmp);
            for(int i=n2-1;i>n/2-1;i--){
                if((mem[m1[i]].a1>mem[m1[i]].a3)&&(n1+1<=n/2)){
                    m1[n1++]=m2[i];
                    n2--;
                }
                else{
                    m3[n3++]=m2[i];
                    n2--;
                }
            }
        }
        if(n3>n/2){
            sort(m3,m3+n3,cmp);
            for(int i=n3-1;i>n/2-1;i--){
                if((mem[m3[i]].a1>mem[m3[i]].a2)&&(n1+1<=n/2)){
                    m1[n1++]=m3[i];
                    n3--;
                }
                else{
                    m2[n2++]=m3[i];
                    n3--;
                }
            }
        }
        for(int i=0;i<n1;i++){
            sum+=mem[m1[i]].a1;
        }
        for(int i=0;i<n2;i++){
            sum+=mem[m2[i]].a2;
        }
        for(int i=0;i<n3;i++){
            sum+=mem[m3[i]].a3;
        }
        printf("%d\n",sum);
    }
    return 0;
}
