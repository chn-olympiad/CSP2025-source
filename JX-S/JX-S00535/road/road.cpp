#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10010],sum,ans;
bool q[10010][10010];
bool find(int x){
    for(int i=1;i<=sum;i++){
        if(a[i]==x) return 0;
    }
    return 1;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int x,y,z;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>z;
        if(find(x)){
            if(find(y)){
                sum++;
                a[sum]=x;
                sum++;
                a[sum]=y;
                ans+=z;
            }else{
                sum++;
                a[sum]=x;
                ans+=z;
            }
        }else if(find(y)){
            sum++;
            a[sum]=y;
            ans+=z;
        }
    }
    cout<<ans;
    return 0;
}
