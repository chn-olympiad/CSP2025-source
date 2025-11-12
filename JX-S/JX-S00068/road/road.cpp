#include<bits/stdc++.h>
using namespace std;
struct bian{
    int tow;
    int nxt;
    int ww;
};
bian lis[1100010] = {};
int f[10100] = {};
int usek[20] = {};
int usew[20] = {};
int findf(int b){
    int l = b;
    while(f[l] != l){
        //<<"???"<<endl;
        l = f[l];
    }
    while(f[b] != l){
        //cout<<"???"<<endl;
        int cnt = b;
        b = f[b];
        f[cnt] = l;
    }
    return l;
}
void hebin(int a,int b){
    int fa = findf(a);
    int fb = findf(b);
    f[fa] = fb;
    f[a] = fb;
}
bool cmp(bian a1,bian a2){
    return a1.ww < a2.ww;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        lis[i].tow = u;
        lis[i].nxt = v;
        lis[i].ww = w;
    }
    for(int i = 1;i<=k;i++){
        int cnttt;
        cin>>cnttt;
        for(int j = 1;j<k;j++){
            m++;
            lis[m].nxt = i+n;
            lis[m].tow = j;
            cin>>lis[m].ww;
        }
    }
    sort(lis+1,lis+m+1,cmp);
    int ans = 0;
    int ti = 1;
    for(int i = 1;i<=n;i++){
        f[i] = i;
    }
    for(int i = 1;i<=n;i++){
            //cout<<i<<endl;
        while(findf(lis[ti].tow) == findf(lis[ti].nxt)){
            ti++;
            if(ti>m){
                break;
            }
        }
        if(lis[ti].nxt>n){
            usek[lis[ti].nxt-n]++;
            if(usek[lis[ti].nxt-n] == 1){
                usew[lis[ti].nxt-n] = lis[ti].ww;
            }
        }
        ans = ans+lis[ti].ww;
        //printf("%d->%d $%d\n",lis[ti].tow,lis[ti].nxt,lis[ti].ww);
        hebin(lis[ti].tow,lis[ti].nxt);
    }
    for(int i = 1;i<=k;i++){
        if(usek[i] == 1){
            ans = ans-usew[i];
        }
    }
    cout<<ans;
}
