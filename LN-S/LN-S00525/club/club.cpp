#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct p{
    int id,v,c;
    //bool operator <(const p&x)const {
    //return v>x.v;}
}a[N*3];
int n,num[5],maxn[N];
bool b[N];
bool cmp(p x,p y){
    return x.v>y.v;
}
int k[N][3];
priority_queue<int,vector<int>,less<int>>q[4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while (T--){
        int ans=0;
        num[1]=num[2]=num[3]=0;
        memset(b,0,sizeof b);
        for (int i=1;i<=3;i++){
            while (!q[i].empty())q[i].pop();
        }
        cin>>n;
        for (int i=0;i<n;i++){
                scanf("%d%d%d",&a[i*3+1].v,&a[i*3+2].v,&a[i*3+3].v);
            k[i][1]=a[i*3+1].v,k[i][2]=a[i*3+2].v,k[i][3]=a[i*3+3].v;
            a[i*3+1].id=a[i*3+2].id=a[i*3+3].id=i;
            a[i*3+1].c=1;a[i*3+2].c=2;a[i*3+3].c=3;
            maxn[i]=max(max(a[i*3+1].v,a[i*3+2].v),a[i*3+3].v);
        }//cout<<"kdpk";
        sort(a+1,a+3*n+1,cmp);
        for (int i=1;i<=3*n;i++){int rt;
            if (b[a[i].id]==1)continue;
            if (num[a[i].c]>=n/2){
                //b[a[i].id]=1;
                //cout<<a[i].v<<"\n";
                if (a[i].c==1){
                    if (q[2].top()>q[3].top())rt=2;
                    else rt=3;
                }
                else if (a[i].c==2){
                    if (q[1].top()>q[3].top())rt=1;
                    else rt=3;
                }
                else {
                    if (q[1].top()>q[2].top())rt=1;
                    else rt=2;
                }
                if (q[rt].top()+a[i].v>0)a[i].v+=q[rt].top(),q[rt].pop(),num[rt]++,num[a[i].c]--;
                else continue;
            }
            //cout<<a[i].v<<"\n";
            ans+=a[i].v;
            b[a[i].id]=1;
            num[a[i].c]++;
            int j=a[i].id;
            if (a[i].c==1){
                q[2].push(k[j][2]-k[j][1]);
                q[3].push(k[j][3]-k[j][1]);
                //cout<<q[2].top()<<" "<<q[3].top()<<" "<<j<<" "<<k[j][2]-k[j][1]<<"\n";
            }
            else if (a[i].c==2){
                q[1].push(k[j][1]-k[j][2]);
                q[3].push(k[j][3]-k[j][2]);
            }
            else {
                q[1].push(k[j][1]-k[j][3]);
                q[2].push(k[j][2]-k[j][3]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
