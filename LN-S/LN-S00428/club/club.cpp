#include<bits/stdc++.h>
#define N 100005
using namespace std;
int T,n,a[N][4],ans,len[4];
struct node{
    int id,da;node(){}
    node(int ii,int dd){id=ii,da=dd;}
};vector<node> vp[4];
bool cmp(node x,node y){return x.da>y.da;}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);ans=0;
        vp[1].clear();vp[2].clear();vp[3].clear();
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            int ac=max(a[i][1],max(a[i][2],a[i][3]));ans+=ac;
            if(ac==a[i][1]){
                vp[1].push_back(node(i,a[i][1]-max(a[i][2],a[i][3])));
            }else if(ac==a[i][2]){
                vp[2].push_back(node(i,a[i][2]-max(a[i][1],a[i][3])));
            }else {
                vp[3].push_back(node(i,a[i][3]-max(a[i][1],a[i][2])));
            }
        }
        sort(vp[1].begin(),vp[1].end(),cmp);
        sort(vp[2].begin(),vp[2].end(),cmp);
        sort(vp[3].begin(),vp[3].end(),cmp);
        len[1]=vp[1].size();len[2]=vp[2].size();len[3]=vp[3].size();
        if(len[1]>n/2){//cout<<"CC 1"<<endl;
            for(int i=len[1]-1;i>=n/2;i--)ans-=vp[1][i].da;
        }
        else if(len[2]>n/2){//cout<<"CC 2"<<endl;
            for(int i=len[2]-1;i>=n/2;i--)ans-=vp[2][i].da;
        }
        else if(len[3]>n/2){//cout<<"CC 3"<<endl;
            for(int i=len[3]-1;i>=n/2;i--)ans-=vp[3][i].da;
        }printf("%d\n",ans);
    }return 0;
}
