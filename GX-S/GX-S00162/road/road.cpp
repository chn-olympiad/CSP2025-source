#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
struct node{
    long long d,f;
    node(){}
    node(int a,int b){
        d=a;
        f=b;
    }
};
long long ss[100100],te[101000];
long long n,m,k,cun[20],dis[101000],bj[100100],sum=0;
vector<node> v[2000100];
priority_queue<int> qu;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(dis,INF,sizeof(dis));
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(node(b,c));
        v[b].push_back(node(a,c));
    }
    for(int i=1;i<=k;i++){
        int x;
        cin>>cun[n+i];
        for(int j=1;j<=n;j++){
            int a;
            cin>>a;
            v[i+n].push_back(node(j,a));
            v[j].push_back(node(i+n,a));
        }
    }
    dis[1]=0;
    qu.push(1);
    for(int i=1;i<=n+k;i++){
        int t=qu.top();
        qu.pop();
        if(bj[t]==1) continue;
        bj[t]=1;
        for(int j=0;j<v[t].size();j++){
            int bh=v[t][j].d,len=v[t][j].f;
 //           cout<<bh<<" "<<dis[bh]<<" "<<t<<" "<<len<<" "<<cun[t]<<endl;
            if(dis[bh]>len+cun[t]){
                dis[bh]=len+cun[t];
                if(cun[t]!=0){
                   if(te[bh]!=t){
                        ss[te[bh]]=0;
                        te[bh]=t;
                   }
                   ss[t]++;
                }
                else{
                    if(te[bh]!=0) ss[te[bh]]--;
                }
                qu.push(bh);
            }
        }
    }
    for(int i=1;i<=n+k;i++){
        sum+=dis[i];
  //      cout<<dis[i]<<endl;
    }
    for(int i=n+1;i<=n+k;i++){
 //       cout<<ss[i]<<" "<<dis[i]<<endl;
        if(ss[i]!=0) sum=sum-(ss[i]-1)*cun[i];
        if(ss[i]==0) sum-=dis[i];
    }
    cout<<sum;
    return 0;
}
