#include<bits/stdc++.h>
using namespace std;
const int N=100100;
int t,n,an;
struct stu{
    int lv;//losted value
    int v;//value
    int i;//id of students
    int j;//id of departments
    int lvj;
    bool operator < (stu a)const{
        return lv>a.lv;
    }
}a[N];
int vis[N];//is 'i' visited?
int num[N];//how many people are there in id:'i'?
priority_queue<stu> p1;
priority_queue<stu> p2;
priority_queue<stu> p3;
bool cmp(stu a,stu b){
    return a.v>b.v;
}
long long ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        an=0;
        ans=0;
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        memset(num,0,sizeof(num));
        while(!p1.empty())p1.pop();
        while(!p2.empty())p2.pop();
        while(!p3.empty())p3.pop();
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                an++;
                cin>>a[an].v;
                a[an].i=i;
                a[an].j=j;
            }
            int mx,mn,md;
            int mxj,mnj,mdj;
            for(int j=1;j<=3;j++)
                if(a[an-j+1].v>=a[an-2].v&&a[an-j+1].v>=a[an-1].v&&a[an-j+1].v>=a[an].v)
                    mx=a[an-j+1].v,mxj=an-j+1;
                else if(a[an-j+1].v<=a[an-2].v&&a[an-j+1].v<=a[an-1].v&&a[an-j+1].v<=a[an].v)
                    mn=a[an-j+1].v,mnj=an-j+1;
                else md=a[an-j+1].v,mdj=an-j+1;
            for(int j=1;j<=3;j++)
                if(a[an-j+1].v>=a[an-2].v&&a[an-j+1].v>=a[an-1].v&&a[an-j+1].v>=a[an].v)
                    a[an-j+1].lv=a[an-j+1].v-md,a[an-j+1].lvj=mdj;
                else if(a[an-j+1].v<=a[an-2].v&&a[an-j+1].v<=a[an-1].v&&a[an-j+1].v<=a[an].v)
                    a[an-j+1].lv=a[an-j+1].v;//!
                else a[an-j+1].lv=a[an-j+1].v-mn,a[an-j+1].lvj=mnj;
        }
        sort(a+1,a+an+1,cmp);
        for(int i=1;i<=an;i++){
            int ids=a[i].i,idd=a[i].j;
            if(vis[ids]==1) continue;
            if(num[idd]==n/2){
                stu temp;
                if(idd==1){
                    temp=p1.top();
                    if(temp.lv<a[i].v)
                        p1.pop(),p1.push(a[temp.lvj]),ans-=temp.lv,num[idd]--,num[a[temp.lvj].j]++;
                    else continue;
                }
                if(idd==2){
                    temp=p2.top();
                    if(temp.lv<a[i].v)
                        p2.pop(),p2.push(a[temp.lvj]),ans-=temp.lv,num[idd]--,num[a[temp.lvj].j]++;
                    else continue;
                }
                if(idd==3){
                    temp=p3.top();
                    if(temp.lv<a[i].v)
                        p3.pop(),p3.push(a[temp.lvj]),ans-=temp.lv,num[idd]--,num[a[temp.lvj].j]++;
                    else continue;
                }
            }
            if(num[idd]<n/2){
                ans+=a[i].v;
                if(idd==1) p1.push(a[i]);
                if(idd==2) p2.push(a[i]);
                if(idd==3) p3.push(a[i]);
                vis[ids]=1;
                num[idd]++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
