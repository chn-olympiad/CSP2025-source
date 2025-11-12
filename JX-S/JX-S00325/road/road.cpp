#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int y[N],n,m,k,x[20],z[20],l[20],b[20];
struct Node{
    int p,q,w;
};
Node e[N];
unsigned long long q;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>e[i].p>>e[i].q>>e[i].w;
        q+=e[i].w;
        y[i]=e[i].w;
    }

        cout<<q;
    return 0;
}

