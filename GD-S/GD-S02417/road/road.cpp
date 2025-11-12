#include<bits/stdc++.h>
using namespace std;
int f[1005],n,m,k,t1,t2,t3,i,j,s,ans=0;
struct ooo{
    int u,v,w;
    bool operator<(const ooo & other){
        return w<other.w;
    }
};
vector<ooo> p,c[10];
int find(const int & g){
    if(f[g]!=g) f[g]=find(f[g]);
    return f[g];
}
bool unit(const int & a,const int & b){
    int s1=find(a),s2=find(b);
    if(s1!=s2) f[s1]=s2;
    else return false;
    return true;
}
void init(const int & g){
    for(int i=1;i<=g;i++) f[i]=i;
}
int ku(){
	init(n);
    int sum=0;
    sort(p.begin(),p.end());
    for(auto & i:p){
        if(unit(i.u,i.v)) sum+=i.w;
    }
    return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(i=0;i<m;i++){
        cin>>t1>>t2>>t3;
        p.push_back({t1,t2,t3});
    }
    for(i=0;i<k;i++){
        cin>>s;
        if(s!=0) ans++;
        for(j=0;j<n;j++){
            cin>>t1>>t2;
            if(s==0) p.push_back({i+1,t1,t2});
            else c[ans-1].push_back({i+1,t1,t2});
        }
    }
    if(ans==0) cout<<ku();
    else{
        ;
    }
    return 0;
}
