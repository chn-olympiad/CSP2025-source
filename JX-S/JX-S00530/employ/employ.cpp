#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m,a[100010],b[100010],av[100010];
int e=0,v[10010][10010],nv=0,vc[10010];
bool zh(int x){
    int e=0;
    for(int i=1;i<=n;i++){
        if(v[x][i]!=vc[i]){
            e=1;
            break;
        }
    }
    return e;
}
bool pd(vector<int> c){
    memset(vc,0,sizeof(vc));
    for(int i=0;i<c.size();i++) vc[c[i]]++;
    int ce=0;
    for(int i=1;i<=nv;i++){
        if(zh(i)==0){
            ce=1;
            break;
        }
    }
    if(ce==1) return 0;
    for(int i=1;i<=n;i++){
        v[++nv][i]=vc[i];
    }
    return 1;
}
void dfs(int s,int x,vector<int> c){
    if(x>=n){
        if(c.size()>=m&&pd(c)==1){
            e++;
            return ;
        }
    }
    if(m-c.size()>(n-x)) return ;
    for(int i=1;i<=n;i++){
        int ea=(a[i]==1?0:1);
        if(av[i]==0){
            av[i]=1;
            if(b[i]>s&&a[i]==1){
                c.push_back(i);
                dfs(s+ea,x+1,c);
                c.pop_back();
            }else dfs(s+ea+1,x+1,c);
            av[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    int tA=0,t=0;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        a[i]=c-'0';
        if(a[i]!=1) tA=1;
        if(a[i]==0) t++;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    if(m==1) tA=0;
    if(tA==1){
        vector<int> c;
        dfs(0,0,c);
        cout<<e;
    }else{
        long long t=1;
        for(int i=1;i<=n-tA;i++){
            t=(t*i)%M;
        }
        cout<<t;
    }
    return 0;
}
