#include<bits/stdc++.h>
using namespace std;
struct member{
    int id,v;
}a[3];
bool cmp(member A,member B){return A.v>B.v;}
int t,n,num[3],ans=0;
vector<int> diff[3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<3;i++) diff[i].clear();
        ans=num[0]=num[1]=num[2]=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            a[0].id=0,a[1].id=1,a[2].id=2;
            scanf("%d%d%d",&a[0].v,&a[1].v,&a[2].v);
            sort(a,a+3,cmp);
            num[a[0].id]++;diff[a[0].id].push_back(a[0].v-a[1].v);ans+=a[0].v;
        }
        int x=num[0],y=num[1],z=num[2],pos=0;
        sort(num,num+3);
        if(x==num[2]) pos=0;
        if(y==num[2]) pos=1;
        if(z==num[2]) pos=2;
        sort(diff[pos].begin(),diff[pos].end());
        if(num[2]>n/2){
            for(int i=0;i<num[2]-n/2;i++) ans-=diff[pos][i];
        }
        printf("%d\n",ans);
    }
    return 0;
}