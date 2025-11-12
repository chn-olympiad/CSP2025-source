#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int a[N][5],b1[N],b2[N],b3[N];
int t;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int n,n1=0,n2=0,n3=0;
        cin>>n;
        int l=n/2;
        ll ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            ans+=max(a[i][1],max(a[i][2],a[i][3]));
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])n1++,b1[n1]=a[i][1]-max(a[i][2],a[i][3]);
            else if(a[i][2]>=a[i][3])n2++,b2[n2]=a[i][2]-max(a[i][1],a[i][3]);
            else n3++,b3[n3]=a[i][3]-max(a[i][2],a[i][1]);
        }
        if(n1>l){
            sort(b1+1,b1+n1+1);
            for(int i=1;i<=n1-l;i++)ans-=b1[i];
        }
        else if(n2>l){
            sort(b2+1,b2+n2+1);
            for(int i=1;i<=n2-l;i++)ans-=b2[i];
        }
        else if(n3>l){
            sort(b3+1,b3+n3+1);
            for(int i=1;i<=n3-l;i++)ans-=b3[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
