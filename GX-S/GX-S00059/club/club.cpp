#include<bits/stdc++.h>
using namespace std;
struct he{
    int maxn;
    int a;
    int b;
    int c;
    int z;
}id[100010];
bool cmp(he a,he b){
    return a.maxn>b.maxn;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long ans=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>id[i].a>>id[i].b>>id[i].c;
            id[i].maxn=max(id[i].a,max(id[i].b,id[i].c));
            if(id[i].maxn==id[i].a) id[i].z=1;
            else if(id[i].maxn==id[i].b) id[i].z=2;
            else{
                id[i].z=3;
            }
        }
        sort(id+1,id+1+n,cmp);
        int suma=0,sumb=0,sumc=0;
        for(int i=1;i<=n;i++){
            if(suma<n/2&&id[i].a>id[i].b){
                suma++;
                ans+=id[i].a;
            }
            else if(sumb<n/2&&id[i].b>id[i].a){
                sumb++;
                ans+=id[i].b;
            }
            else if(suma<n/2){
                suma++;
                ans+=id[i].a;
            }
            else if(sumb<n/2){
                sumb++;
                ans+=id[i].b;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
