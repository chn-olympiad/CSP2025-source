#include<bits/stdc++.h>
using namespace std;
long long a[100010];
long long st[100010];
long long fk[100010];
long long used[10010][10010];
long long da=0;
long long n;
void dfs(long long x,long long g,long long u){
    if(x>g){
        long long maxx=-0x3f3f3f3f;
        long sum=0;
        for(long long  i=1;i<=g;i++){
            if(fk[i]>=maxx){
                maxx=fk[i];
            }
            sum+=fk[i];
        }
        if(sum>maxx*2){
            da++;
            //for(long long  i=1;i<=g;i++){
              //  cout<<fk[i]<<" ";
           // }
           // cout<<endl;
        }
    }

    for(long long i=u;i<=n;i++){
        fk[x]=a[i];
        dfs(x+1,g,i+1);
        fk[x]=0;
    }
}
int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }

    for(int o=3;o<=n;o++){
        dfs(1,o,1);
    }
    cout<<da%998244353;


    return 0;
}

