#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct data{
    int val;
    int i;
    short type;
};
vector<data> v;
int a[100010][4],ans;
bool cant_use[100010];
vector<int> plan[4];
bool cmp(data x,data y){
    return x.val>y.val;
}
int T,n,type;
vector<int> v1,v2;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%d",&n);
        for(int j=1;j<=n;j++){
            scanf("%d%d%d",&a[j][1],&a[j][2],&a[j][3]);
            if(a[j][1]>=a[j][2] && a[j][1]>=a[j][3]){
                plan[1].push_back(j);
                ans+=a[j][1];
            }else if(a[j][2]>=a[j][1] && a[j][2]>=a[j][3]){
                plan[2].push_back(j);
                ans+=a[j][2];
            }else{
                plan[3].push_back(j);
                ans+=a[j][3];
            }
        }
        for(int type=1;type<=3;type++){
            if(plan[type].size()>n/2){
                int sz=plan[type].size()-n/2;
                for(int i=0;i<plan[type].size();i++){
                    if(type!=1)v.push_back({a[plan[type][i]][type]-a[plan[type][i]][1],plan[type][i],1});
                    if(type!=2)v.push_back({a[plan[type][i]][type]-a[plan[type][i]][2],plan[type][i],2});
                    if(type!=3)v.push_back({a[plan[type][i]][type]-a[plan[type][i]][3],plan[type][i],3});
                    //lose,id,type
                }
                sort(v.begin(),v.end(),cmp);
                for(int j=1;j<=sz;j++){
                    if(plan[v.back().type].size()<=n/2-1){
                        if(cant_use[v.back().i]){
                            v.pop_back();
                            j--;
                            continue;
                        }
                        plan[v.back().type].push_back(v.back().i);
                        cant_use[v.back().i]=1;
                        ans-=v.back().val;
                        v.pop_back();
                    }else{
                        v.pop_back();
                    }
                }
                break;
            }
        }
        printf("%d\n",ans);
        memset(a,0,sizeof(a));
        memset(cant_use,0,100010);
        v.clear();
        ans=0;
        for(int i=1;i<=3;i++){
            plan[i].clear();
        }
    }
    return 0;
}
