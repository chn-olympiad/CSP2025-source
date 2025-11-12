#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=100010;
int n;
int T;
struct node{
    int a,b,c;
    int maxn1,maxn2;
    int id;
}stu[N];
bool cmp(node x,node y){
    return x.maxn1>y.maxn1;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&stu[i].a,&stu[i].b,&stu[i].c);
            stu[i].maxn1=max({stu[i].a,stu[i].b,stu[i].c});
            if(stu[i].a==stu[i].maxn1) stu[i].maxn2=max(stu[i].b,stu[i].c);
            else if(stu[i].b==stu[i].maxn1) stu[i].maxn2=max(stu[i].a,stu[i].c);
            else stu[i].maxn2=max(stu[i].a,stu[i].b);
            stu[i].id=i;
        }
        sort(stu+1,stu+n+1,cmp);
        priority_queue<PII,vector<PII>,greater<PII>> ha,hb,hc;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(stu[i].a==stu[i].maxn1){
                if(ha.size()==n/2 && stu[i].maxn1-stu[i].maxn2>=ha.top().first){
                    ans-=ha.top().first;
                    ha.pop();
                    ans+=stu[i].a;
                    ha.push({stu[i].maxn1-stu[i].maxn2,stu[i].id});
                }
                else if(ha.size()<n/2){
                    ans+=stu[i].a;
                    ha.push({stu[i].a-stu[i].maxn2,stu[i].id});
                }
                else ans+=stu[i].maxn2;
            }
            else if(stu[i].b==stu[i].maxn1){
                if(hb.size()==n/2 && stu[i].maxn1-stu[i].maxn2>=hb.top().first){
                    ans-=hb.top().first;
                    hb.pop();
                    ans+=stu[i].b;
                    hb.push({stu[i].maxn1-stu[i].maxn2,stu[i].id});
                }
                else if(hb.size()<n/2){
                    ans+=stu[i].b;
                    hb.push({stu[i].b-stu[i].maxn2,stu[i].id});
                }
                else ans+=stu[i].maxn2;
            }
            else{
                if(hc.size()==n/2 && stu[i].maxn1-stu[i].maxn2>=hc.top().first){
                    ans-=hc.top().first;
                    hc.pop();
                    ans+=stu[i].c;
                    hc.push({stu[i].maxn1-stu[i].maxn2,stu[i].id});
                }
                else if(hc.size()<n/2){
                    ans+=stu[i].c;
                    hc.push({stu[i].c-stu[i].maxn2,stu[i].id});
                }
                else ans+=stu[i].maxn2;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*

*/
