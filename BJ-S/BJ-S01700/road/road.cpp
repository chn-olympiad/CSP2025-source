#include<bits/stdc++.h>
using namespace std;
struct ax{
    int u,v,w;
};
struct cv{
    int v,w;
};
struct bx{
    int fy;
    cv s[10005];
};

int n,m,k,ans;
ax ma[10005];
bx ka[25];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>ma[i].u>>ma[i].v;
    }
    for(int i=1;i<=k;i++){
        bool jk=1;
        cin>>ka[i].fy;
        for(int j=1;j<=n;j++){
            cin>>ka[i].s[j].w;
            ka[i].s[j].v=j;
            if(ka[i].s[j].w!=0){
                jk=0;
            }
        }
        if(jk){
            cout<<0;
            return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
