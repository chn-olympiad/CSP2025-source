#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5+105;

inline int rd(){
    int r=0,w=1;char c=getchar();
    while(!isdigit(c)) (c=='-')&&(w=-1),c=getchar();
    while(isdigit(c)) r=r*10-'0'+c,c=getchar();
    return r*w;
}

int T,n,a[N][4],ans;
vector<int> c[4];

inline int getval(int x,int p){
    if(p==1) return min(a[x][p]-a[x][2],a[x][p]-a[x][3]);
    if(p==2) return min(a[x][p]-a[x][1],a[x][p]-a[x][3]);
    if(p==3) return min(a[x][p]-a[x][1],a[x][p]-a[x][2]);
}

int main(){
    freopen("club.in","r",stdin);freopen("club.out","w",stdout);
    T=rd();

    while(T--){
        n=rd();
        for(int i=1;i<=3;++i) c[i].clear();
        for(int i=1;i<=n;++i){
            a[i][1]=rd(),a[i][2]=rd(),a[i][3]=rd();
            if(a[i][1]>a[i][2] && a[i][1]>a[i][3]){
                c[1].push_back(i);ans+=a[i][1];
            }else if(a[i][2]>a[i][3]){
                c[2].push_back(i);ans+=a[i][2];
            }else{
                c[3].push_back(i);ans+=a[i][3];
            }
        }
        for(int i=1;i<=3;++i){
            if(c[i].size()>n/2){
                sort(c[i].begin(),c[i].end(),[&](int x,int y){return getval(x,i)>getval(y,i);});
                //for(int x:c[i]) cerr<<"*"<<x<<endl;
                //cerr<<"ans:"<<ans<<endl; 
                for(int j=n/2;j<c[i].size();++j) ans-=getval(c[i][j],i);
            }
        }
        printf("%d\n",ans);
        ans=0;
    }

    return 0;
}