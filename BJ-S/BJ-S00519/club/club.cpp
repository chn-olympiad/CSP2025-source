#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int n;
int a[N][3],d[N],c[3],b[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        int ans=0;
        c[0]=c[1]=c[2]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            d[i]=0;
            if(a[i][1]>a[i][d[i]])d[i]=1;
            if(a[i][2]>a[i][d[i]])d[i]=2;
            ans+=a[i][d[i]],c[d[i]]++;
        }
        int D=0;
        if(c[1]>c[D])D=1;
        if(c[2]>c[D])D=2;
        if(c[D]<=n/2){
            cout<<ans<<'\n';
            continue;
        }
        int m=0;
        for(int i=1;i<=n;i++){
            if(d[i]!=D)continue;
            b[++m]=0;
            if(D!=0)b[m]=max(b[m],a[i][0]);
            if(D!=1)b[m]=max(b[m],a[i][1]);
            if(D!=2)b[m]=max(b[m],a[i][2]);
            b[m]=a[i][D]-b[m];
        }
        sort(b+1,b+m+1);
        for(int i=1;i<=c[D]-n/2;i++)ans-=b[i];
        cout<<ans<<'\n';
    }
    return 0;
}
