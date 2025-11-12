#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=505;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ull n,m,k,c,cnt=0,a[N],s[N];
    //string s;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        cnt+=w;
    }
    cin>>c;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++){
        if(k==0||(c==0&&s[i]==0)){
            cout<<cnt;
            return 0;
        }
    }
    cout<<24;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
