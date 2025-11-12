#include<iostream>
#include<queue>
#define maxn 100005
#define ll long long
using namespace std;
int T;
int n;
struct stu{
    ll num,k;
}a1[maxn],a2[maxn],a3[maxn];
priority_queue<stu,vector<stu>,greater<stu>>v1,v2,v3;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>T;
    while(T--){
        ll ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a1[i].num,&a2[i].num,&a3[i].num);
            a1[i].k=a2[i].k=a3[i].k=i;
        }
        for(int i=1;i<=n;i++){
            if(a1[i].num>a2[i].num&&a1[i].num>a3[i].num){
                if(v1.size()<=n/2)
                    v1.push({a1[i].num,a1[i].k});
                else{
                    int index=v1.top().k;
                    if(a2[index].num>a3[index].num)v2.push({a2[index].num,index});
                    else v3.push((stu){a3[index].num,index});
                    v1.pop();
                    v1.push({a1[i].num,a1[i].k});
                }
            }else if(a2[i].num>a1[i].num&&a2[i].num>a3[i].num){
                if(v2.size()<=n/2)
                    v2.push({a2[i].num,a2[i].k});
                else{
                    int index=v2.top().k;
                    if(a1[index].num>a3[index].num)v2.push({a1[index].num,index});
                    else v2.push({a3[index].num,index});
                    v2.pop();
                    v2.push({a2[i].num,a2[i].k});
                }
            }else{
                if(v3.size()<=n/2)
                    v3.push({a3[i].num,a3[i].k});
                else{
                    int index=v3.top().k;
                    if(a1[index].num>a2[index].num)v3.push({a1[index].num,index});
                    else v3.push({a2[index].num,index});
                    v3.pop();
                    v3.push({a3[i].num,a3[i].k});
                }

            }

            for(int i=0;i<v1.size();i++){
                ans+=v1.top().num;
                v1.pop();
            }
            for(int i=0;i<v2.size();i++){
                ans+=v2.top().num;
                v2.pop();
            }
            for(int i=0;i<v3.size();i++){
                ans+=v3.top().num;
                v3.pop();
            }
            cout<<ans<<endl;
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
