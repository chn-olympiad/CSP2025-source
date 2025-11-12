#include<bits/stdc++.h>
#define int long long
using namespace std;

struct road1{
    int u,v,w;
};
int n,m,k;
road1 a[5001000];

bool cmp(road1 x,road1 y){
    return x.w<y.w;
}

int fa[10010];
int lian[10010];

int find1(int x){
    if(fa[x]==x){
        return x;
    }
    fa[x]=find1(fa[x]);
    return fa[x];
}

int num[10100];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin >> n >> m >>k;
    for(int i=1;i<=m;i++){
        cin >> a[i].u >>a[i].v >>a[i].w;
    }

    for(int i=1;i<=k;i++){
        int c;
        cin >>c;

        int flag=0;
        for(int j=1;j<=n;j++){
            cin >> num[j];
            if(num[j]==0){
                flag=j;
            }
        }
        for(int k1=1;k1<=n;k1++){
            if(k1!=flag){
                m++;
                a[m].u=flag;
                a[m].v=k1;
                a[m].w=num[k1];
            }
        }
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=n;i++){
        fa[i]=i;
        lian[i]=1;
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        if(find1(a[i].u)!=find1(a[i].v)){
            lian[find1(a[i].v)]+=lian[find1(a[i].u)];
            fa[find1(a[i].u)]=find1(a[i].v);
            ans+=a[i].w;
            if(lian[find1(a[i].v)]==n){
                break;
            }
        }
    }
    cout << ans;

    return 0;
}
