#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10,M = 1e6+10;
long long n,m,k,f[N];
struct node{
    long long from,to,val;
}a[M];
bool cmp(node xx,node yy){
    return xx.val < yy.val;
}
int find(int p){
    if(f[p] != p) return f[p] = find(f[p]);
    return f[p];
}
void merge(long long p1,long long p2){
    f[find(p1)] = find(p2);
}
long long ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i = 1;i <= m;i++) cin>>a[i].from>>a[i].to>>a[i].val;
    for(int i = 1;i <= k;i++){
        int c,x;
        cin>>c;
        for(int j = 1;j <= n;j++){
            cin>>x;
        }
    }
    sort(a+1,a+1+m,cmp);
    for(int i = 1;i <= n;i++) f[i] = i;
    int connected = 0;
    for(int i = 1;i <= m;i++){
        if(connected == n-1) break;
        if(find(a[i].from) != find(a[i].to)) {
            f[find(a[i].to)] = a[i].from;
            
            ans += a[i].val;
            connected++;
        }
    }
    cout<<ans;
    return 0;
}