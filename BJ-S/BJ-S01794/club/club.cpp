#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int a[N][5];
int ch[N];
int g[5];
int b[N],cur;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        g[1]=g[2]=g[3]=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            int id=1;
            if(a[i][2]>a[i][id])id=2;
            if(a[i][3]>a[i][id])id=3;
            ans+=a[i][id];
            g[id]++;
            ch[i]=id;
        }
        int p=0;
        for(int i=1;i<=3;i++)
            if(g[i]>n/2)p=i;
        if(p==0){
            cout<<ans<<"\n";
            continue;
        }
        swap(g[1],g[p]);
        cur=0;
        for(int i=1;i<=n;i++){
            swap(a[i][1],a[i][p]);
            if(ch[i]==p)b[++cur]=max(a[i][2],a[i][3])-a[i][1];
        }
        sort(b+1,b+cur+1);
        for(int i=cur;i>=cur-(g[1]-n/2)+1;i--)ans+=b[i];
        cout<<ans<<"\n";
    }
    return 0;
}
