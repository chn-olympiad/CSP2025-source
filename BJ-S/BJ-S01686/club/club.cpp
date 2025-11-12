#include <bits/stdc++.h>
using namespace std;
int n;
int a[4][200010];
int T;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[j][i];
            }
        }
        long long cnt=0;
        sort(a[1]+1,a[1]+n+1,cmp);
        for(int i=1;i<=n/2;i++){
            cnt+=a[1][i];
        }
        cout<<cnt<<endl;
    }
}
//顶多5分
//-S还是不会阿
//脑子转爆了
//我写了什么啊
//存爆炸代码：回家搞八
// #include <bits/stdc++.h>
// using namespace std;
// int n;
// int a[100010][4];
// int pa[100010],pb[100010],pc[100010];
// short sec[100010],thi[100010],fir[100010];
// int ta,tb,tc;
// int T;
// bool cmp(int x,int y){
//     return x>y;
// }
// int main(){
//     freopen("club.in","r",stdin);
//     freopen("club.out","w",stdout);
//     cin>>T;
//     while(T--){
//         memset(pa,0,sizeof(pa));
//         memset(pb,0,sizeof(pb));
//         memset(pc,0,sizeof(pc));
//         memset(sec,0,sizeof(sec));
//         memset(thi,0,sizeof(thi));
//         memset(fir,0,sizeof(fir));
//         ta=0;tb=0;tc=0;
//         bool flag=true;
//         cin>>n;
//         int ans=0;
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=3;j++){
//                 cin>>a[i][j];
//                 if(j>=2&&a[i][j]>0){
//                     flag=false;
//                 }
//             }
//             int tmpa=a[i][1];
//             int tmpb=a[i][2];
//             int tmpc=a[i][3];
//             a[i][1]=max(tmpa,max(tmpb,tmpc));
//             a[i][3]=min(tmpc,min(tmpa,tmpb));
//             a[i][2]=tmpa+tmpb+tmpc-a[i][1]-a[i][3];
//             if(tmpa>tmpc&&tmpa>tmpb){
//                 ans+=a[i][1];
//                 ta++;
//                 pa[ta]=i;
//             }
//             else if(tmpb>tmpc&&tmpb>tmpa){
//                 ans+=a[i][2];
//                 tb++;
//                 pb[tb]=i;
//             }else{
//                 ans+=a[i][3];
//                 tc++;
//                 pc[tc]=i;
//             }
//             if(a[i][2]==tmpa){
//                 sec[i]=1;
//             }else if(a[i][2]==tmpb){
//                 sec[i]=2;
//             }else{
//                 sec[i]=3;
//             }
//             if(a[i][3]==tmpa){
//                 thi[i]=1;
//             }else if(a[i][3]==tmpb){
//                 thi[i]=2;
//             }else{
//                 thi[i]=3;
//             }
//             if(a[i][1]==tmpa){
//                 fir[i]=1;
//             }else if(a[i][1]==tmpb){
//                 fir[i]=2;
//             }else{
//                 fir[i]=3;
//             }
//         }
//         cout<<ta<<" "<<tb<<endl;
//         //暴力枚举删哪个！
//         if(ta>n/2){
//             int fa[200010];
//             for(int i=1;i<=ta;i++){
//                 fa[i]=a[pa[i]][1];
//             }
//             sort(fa+1,fa+ta+1);
//             int i=1;

//             while(ta>n/2){
//                 ta--;
//                 ans-=fa[i];
//                 // cout<<fa[i]<<" "<<ans<<endl;
//                 ans+=a[pa[i]][2];
//                 if(sec[pa[i]]==2){
//                     tb++;
//                     sec[pa[i]]=thi[pa[i]];
//                     thi[pa[i]]=fir[pa[i]];
//                     swap(a[pa[i]][1],a[pa[i]][2]);
//                     swap(a[pa[i]][2],a[pa[i]][3]);
//                 }else if(tc<=n/2){
//                     tc++;
//                     sec[pa[i]]=fir[pa[i]];
//                     thi[pa[i]]=sec[pa[i]];
//                     swap(a[pa[i]][1],a[pa[i]][2]);
//                     swap(a[pa[i]][2],a[pa[i]][3]);
//                 }
//                 i++;
//             }
//         }
//         if(tb>n/2&&ta==n/2){
//             int fb[200010];
//             for(int i=1;i<=tb;i++){
//                 fb[i]=a[pb[i]][1];
//             }
//             sort(fb+1,fb+tb+1);
//             int i=1;
//             while(tb>n/2){
//                 tb--;
//                 ans-=fb[i];
//                 // cout<<fb[i]<<" "<<ans<<endl;
//                 if(sec[pb[i]]==3){
//                     ans+=a[pb[i]][2];
//                     tc++;
//                 }else{
//                     ans+=a[pb[i]][3];
//                     tc++;
//                 }
//                 i++;
//             }
//         }else if(tb>n/2){
//             int fb[200010];
//             for(int i=1;i<=tb;i++){
//                 fb[i]=a[pb[i]][1];
//             }
//             sort(fb+1,fb+tb+1);
//             int i=1;

//             while(tb>n/2){
//                 tb--;
//                 ans-=fb[i];
//                 // cout<<fa[i]<<" "<<ans<<endl;
//                 ans+=a[pb[i]][2];
//                 if(sec[pb[i]]==1){
//                     ta++;
//                     sec[pb[i]]=fir[pb[i]];
//                     thi[pb[i]]=sec[pb[i]];
//                     swap(a[pb[i]][1],a[pb[i]][2]);
//                     swap(a[pb[i]][2],a[pb[i]][3]);
//                 }else{
//                     tc++;
//                     sec[pb[i]]=fir[pb[i]];
//                     thi[pb[i]]=sec[pb[i]];
//                     swap(a[pb[i]][1],a[pb[i]][2]);
//                     swap(a[pb[i]][2],a[pb[i]][3]);
//                 }
//                 i++;
//             }
//         }
//         cout<<ans<<endl;
//     }
// }
//bye csp