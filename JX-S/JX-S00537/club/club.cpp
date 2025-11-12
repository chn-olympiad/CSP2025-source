#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int t,n,q;
int a[N],b[N],c[N],m[N],w,r;
int a1,b1,c1;
long long ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            m[i]=abs(a[i]-b[i]);
            if(m[i]<m[i-1]){
                swap(a[i],a[i-1]);
                swap(b[i],b[i-1]);
                swap(c[i],c[i-1]);
            }
            w+=c[i];
            r+=b[i];
        }
        for(int i=n;i>=1;i--){
            if(a1>=n/2){
                a[i]=-1;
            }
            if(b1>=n/2){
                b[i]=-1;
            }
            if(c1>=n/2){
                c[i]=-1;
            }
            if(a[i]==max(max(a[i],b[i]),c[i])){
                int e=a[i];
                    a1++;
                    ans+=e;
            }
            else if(b[i]==max(max(a[i],b[i]),c[i])){
                int e=b[i];
                    b1++;
                    ans+=e;
            }
            else if(c[i]==max(max(a[i],b[i]),c[i])){
                int e=c[i];
                    c1++;
                    ans+=e;
            }
        }
        cout<<ans<<endl;
        ans=0;
        a1=0;
        b1=0;
        c1=0;
    }
    return 0;
}
