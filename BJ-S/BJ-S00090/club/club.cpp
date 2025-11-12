#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
int a[MAXN][3];
struct node{
    int w, id, ch;
};
bool cmp(node a, node b){
    return a.ch < b.ch;
}
node t1[MAXN], t2[MAXN], t3[MAXN];
int n;
int main(){
    int T;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        memset(a,0,sizeof(a));
        memset(t1,0,sizeof(t1));
        memset(t2,0,sizeof(t2));
        memset(t3,0,sizeof(t3));
        cin>>n;
        int ans  = 0;
        int c1 = 0, c2 = 0, c3 = 0;
        for(int i = 1; i <= n; i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            int b[4];
            b[1] = a[i][1], b[2] = a[i][2], b[3] = a[i][3];

            //find biggest and scd bgst number

            if(b[1] > b[2]){
                swap(b[1],b[2]);
            }
            if(b[2] > b[3]){
                swap(b[2],b[3]);
            }
            if(b[1] > b[2]){
                swap(b[1],b[2]);
            }

            //find biggest index

            if(a[i][1] == b[3]){
                t1[++c1] = (node){a[i][1], i, b[3]-b[2]};
            }else if(a[i][2] == b[3]){
                t2[++c2] = (node){a[i][2], i, b[3]-b[2]};
            }else if(a[i][3] == b[3]){
                t3[++c3] = (node){a[i][3], i, b[3]-b[2]};
            }
            ans += b[3];
        }
        if(c1 > n/2){
            sort(t1+1,t1+1+c1,cmp);
            for(int i = 1; i <= c1-n/2; i++){
                ans -= t1[i].ch;
            }
        }else if(c2 > n/2){
            sort(t2+1,t2+1+c2,cmp);
            for(int i = 1; i <= c2-n/2; i++){
                ans -= t2[i].ch;
            }
        }else if(c3 > n/2){
            sort(t3+1,t3+1+c3,cmp);
            for(int i = 1; i <= c3-n/2; i++){
                ans -= t3[i].ch;
            }
        }
        cout<<ans<<endl;
    }
}
