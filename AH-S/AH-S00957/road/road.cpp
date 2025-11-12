#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N = 5e6 + 5;
struct Node{
    int u,v,w;//from u to v need w
}a[N];
int in = 1;
bool cmp(Node x,Node y){
    return x.w < y.w;
}
int v[1005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a[in].u,&a[in].v,&a[in].w);
        in++;
    }
    if(k == 0){
        int sum = 0;
        sort(a,a+in,cmp);
        int flag = 0;
        for(int i=1;i<=m;i++){
            flag = 0;
            for(int j=1;j<=n;j++){
                if(v[i] == 1){
                    flag++;
                }
            }
            if(flag == n-1){
                break;
            }
            if(v[a[i].v] == 0){
                sum = sum + a[i].w;
                v[a[i].v] = 1;
            }
        }
        cout<<sum;
    }else{
        cout<<"0";
    }
    return 0;
}
