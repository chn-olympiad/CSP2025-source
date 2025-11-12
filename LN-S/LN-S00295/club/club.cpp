#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+5;
struct node{
    int a,b,c;
    int cha1;
    int mid;
}s[N];
int c[5][N];
int c1,c2,c3;
bool cmp(int x,int y){
    return s[x].cha1<s[y].cha1;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        c1=c2=c3=0;
        int n;
        long long ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
            s[i].mid=s[i].a+s[i].b+s[i].c-max(s[i].a,max(s[i].b,s[i].c))-min(s[i].a,min(s[i].b,s[i].c));
            s[i].cha1=max(s[i].a,max(s[i].b,s[i].c))-s[i].mid;
            if(max(s[i].a,max(s[i].b,s[i].c))==s[i].a){
                c[1][++c1]=i;
                ans+=s[i].a;
            }
            else if(max(s[i].a,max(s[i].b,s[i].c))==s[i].b){
                c[2][++c2]=i;
                ans+=s[i].b;
            }
            else{
                c[3][++c3]=i;
                ans+=s[i].c;
            }
        }
        if(c1>n/2){
            sort(c[1]+1,c[1]+1+c1,cmp);
            for(int i=1;i<=c1-n/2;i++){
                ans-=s[c[1][i]].cha1;
            }
        }else if(c2>n/2){
            sort(c[2]+1,c[2]+1+c2,cmp);
            for(int i=1;i<=c2-n/2;i++){
                ans-=s[c[2][i]].cha1;
            }
        }else{
            sort(c[3]+1,c[3]+1+c3,cmp);
            for(int i=1;i<=c3-n/2;i++){
                ans-=s[c[3][i]].cha1;
            }
        }
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
