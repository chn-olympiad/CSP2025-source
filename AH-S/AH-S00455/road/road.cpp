#include<bits/stdc++.h>
using namespace std;
int n,m,k,d[1005][1005],a[1005],t,cnt;
bool b[1005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    memset(d,0x3f,sizeof(d));
    for(int i=1,p,q,r;i<=m;i++){
        cin>>p>>q>>r;
        d[p][q]=r;
        d[q][p]=r;
        cnt+=r;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
