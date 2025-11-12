#include<bits/stdc++.h>
const int N=1e5+10;
std::vector<int> b[3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
        int c[3]={0,0,0},ans=0;
        for(int i=0;i<3;i++) b[i].clear();
        for(int i=1,a0,a1,a2;i<=n;i++){
            scanf("%d%d%d",&a0,&a1,&a2);
            if(a0>=std::max(a1,a2)) ++c[0],b[0].push_back(a0-std::max(a1,a2)),ans+=a0;
            else if(a1>=std::max(a0,a2)) ++c[1],b[1].push_back(a1-std::max(a0,a2)),ans+=a1;
            else ++c[2],b[2].push_back(a2-std::max(a0,a1)),ans+=a2;
        }
        int k=std::max_element(c,c+3)-c;
        if(c[k]>n/2){
            std::sort(b[k].begin(),b[k].end());
            for(int i=0;i<c[k]-n/2;i++) ans-=b[k][i];
        }
        printf("%d\n",ans);
    }
}