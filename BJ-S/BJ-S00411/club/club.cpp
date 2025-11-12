#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct person{
    int a[4];
};
int mode;
bool cmp(person a,person b){
    int a12=abs(a.a[1]-a.a[2]);
    int a13=abs(a.a[1]-a.a[3]);
    int a23=abs(a.a[3]-a.a[2]);
    int b12=abs(b.a[1]-b.a[2]);
    int b13=abs(b.a[1]-b.a[3]);
    int b23=abs(b.a[3]-b.a[2]);
    int maxx=max({a12,a13,a23});
    if(maxx==a12) return a12>b12;
    if(maxx==a13) return a13>b13;
    else return a23>b23;
}
int sum[4];
int cnt[4];
int n;
vector<person> p;
void throw_person(int modee){
    mode=modee;
    sort(p.begin(),p.end(),cmp);
    queue<person> q;
    for(auto x:p) q.push(x);
    p.resize(0);
    while(!q.empty()){
        person x=q.front();
        q.pop();
        if(max(x.a[1],max(x.a[2],x.a[3]))==x.a[mode]&&cnt[mode]<(n/2)){
            sum[mode]+=x.a[mode];
            cnt[mode]++;
            //cout<<x.a[1]<<" "<<x.a[2]<<" "<<x.a[3]<<":"<<mode<<" cnt["<<mode<<"]:"<<cnt[mode]<<"/"<<n/2<<endl;

        }else{
            //cout<<x.a[1]<<" "<<x.a[2]<<" "<<x.a[3]<<": skip,delete x["<<mode<<"] cnt["<<mode<<"]:"<<cnt[mode]<<"/"<<n/2<<endl;
            x.a[mode]=-1;
            p.push_back(x);
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        p.resize(0);
        for(int i=0;i<n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            p.push_back({{0,x,y,z}});
        }
        memset(sum,0,sizeof sum);
        memset(cnt,0,sizeof cnt);
        throw_person(1);
        throw_person(2);
        throw_person(3);
        // cout<<sum[1]<<" "<<sum[2]<<" "<<sum[3]<<endl;
        cout<<sum[1]+sum[2]+sum[3]<<endl;
    }
    return 0;
}
