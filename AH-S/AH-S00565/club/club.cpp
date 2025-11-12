#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int T;
int n,cnt[4],sum;
struct edge{
    int x,id;
};
struct node{
    edge a[4];
    int f,p1,p2;
}t[100010];
bool cmp(edge a,edge b){
    return a.x>b.x;
}
struct fu{
    edge a[4];
}fz[4][100010];
bool cmp2(fu d,fu f){
    if(d.a[1].x-d.a[2].x!=f.a[1].x-f.a[2].x) return d.a[1].x-d.a[2].x<f.a[1].x-f.a[2].x;
    else return d.a[1].x-d.a[3].x<f.a[1].x-f.a[3].x;
}
int cont[4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        sum=0;
        cont[1]=cont[2]=cont[3]=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&t[i].a[1].x,&t[i].a[2].x,&t[i].a[3].x);
            t[i].a[1].id=1;
            t[i].a[2].id=2;
            t[i].a[3].id=3;
            sort(t[i].a+1,t[i].a+4,cmp);
            fz[t[i].a[1].id][++cont[t[i].a[1].id]].a[1]=edge{t[i].a[1].x,t[i].a[1].id};
            fz[t[i].a[1].id][cont[t[i].a[1].id]].a[2]=edge{t[i].a[2].x,t[i].a[2].id};
            fz[t[i].a[1].id][cont[t[i].a[1].id]].a[3]=edge{t[i].a[3].x,t[i].a[3].id};
            sum+=t[i].a[1].x;
        }
        if(cont[1]>n/2){
            sort(fz[1]+1,fz[1]+cont[1]+1,cmp2);
            int i=0;
            while(cont[1]>n/2){
                i++;
                sum-=(fz[1][i].a[1].x-fz[1][i].a[2].x);
                cont[1]--;
            }
        }
        if(cont[2]>n/2){
            sort(fz[2]+1,fz[2]+cont[2]+1,cmp2);
            int i=0;
            while(cont[2]>n/2){
                i++;
                sum-=(fz[2][i].a[1].x-fz[2][i].a[2].x);
                cont[2]--;
            }
        }
        if(cont[3]>n/2){
            sort(fz[3]+1,fz[3]+cont[3]+1,cmp2);
            int i=0;
            while(cont[3]>n/2){
                i++;
                sum-=(fz[3][i].a[1].x-fz[3][i].a[2].x);
                cont[3]--;
            }
        }
        cout<<sum<<endl;
        memset(t,0,sizeof(t));
        memset(fz,0,sizeof(fz));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
