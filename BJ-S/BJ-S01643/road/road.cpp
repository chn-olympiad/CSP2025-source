#include<bits/stdc++.h>
using namespace std;
const int N = 1e8-10;
struct node{
    int co,id;
}a[N],e[N];
bool cmp(node a,node b){
    if(a.co != 0)return a.co < b.co;
    return b.co < a.co;
}
bool cmp_int (int a,int b){return a < b;}
int b[10005],c[15],d[N];
bool bb[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,ans = 0;
    cin >> n >> m >> k;
    if(k == 0){
        int  kkk[1000005];
        for(int i = 1;i <= m;i++){int x,y;cin >> x >> y >> k[i];}
        sort(a+1,a+m+1,cmp);
        for(int i = 1;i < n;i++){ans += k[i]};
        cout << ans << endl;
        return 0;
    }
    
    for(int i = 1;i <= n*n+n;i++)a[i].co=1e9+5;
    for(int i = 1 ;i <= m;i++){
        int x,y,z;
        cin >> x >> y >> z;
        if(x > y){int t = y;y = x;x = t;}
        a[x*(n+1)+y].co = z;
        a[x*(n+1)+y].id = x*(n+1)+y;
        d[x*(n+1)+y] = z;
    }
    sort(a+1,a+n*(n+1)+1,cmp);
    for(int i = 1;i < n;i++){
        bb[a[i].id] = 1;
        ans += a[i].co;
        //cout << a[i].id << " " <<a[i].co << endl;
    }
    //cout << ans << endl;
    for(int i = 1;i <= k;i++){
        int cnt = ans,now = 0,neww = 0,newww=0;
        cin >> c[i];
        for(int j = 1;j <= n;j++){
            cin >> b[j];
            for(int k = 1;k < j;k++){
                if(bb[k*(n+1)+j] == 0){
                    if(b[j]+b[k] < a[n-1].co){
                        d[k*(n+1)+j] = b[j]+b[k];
                        bb[a[n-1].id] = 0;
                        ans -= (a[n-1].co - b[j] - b[k]);
                        a[n-1].co = b[j]+b[k];
                        a[n-1].id = k*(n+1)+j;
                        e[++now].id = k*(n+1)+j;
                        e[now].co = d[k*(n+1)+j];
                        neww++;
                       // cout << j << " " << k << " " << b[j] << " " << b[k] << " " << ans << endl;
                    }
                }
                else{
                    if(b[j]+b[k] < d[k*(n+1)+j]){
                        ans -= (d[k*(n+1)+j] - b[j] - b[k]);
                        d[k*(n+1)+j] = b[j] + b[k];
                        e[++now].id = k*(n+1)+j;
                        e[now].co = d[k*(n+1)+j];
                        newww++;
                        a[n+newww].id=k*(n+1)+j;
                        a[n+newww].co=b[j]+b[k];
                    }
                }
            }
        }
        //cout << i << " " << c[i] << endl;
        ans += c[i];
        if(ans > cnt){
            ans = cnt;
            for(int j = 1;j <= now;j++){
                d[e[j].id] = e[j].co;
            }
        }
        else{
            for(int i = 1;i <= n;i++){
                for(int j = i+1;j <= n;j++){
                    a[i*(n+1)+j].co=d[i*(n+1)+j];
                }
            }
            sort(a+1,a+n*(n+1)+1,cmp);
            for(int i = 1;i < n;i++){
                bb[a[i].id]=1;
            }

        }
    }
    cout << ans << endl;
}