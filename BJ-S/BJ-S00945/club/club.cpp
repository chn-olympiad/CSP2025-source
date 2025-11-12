#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N];
int n;
vector<int> va,vb,vc;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        va.clear();
        vb.clear();
        vc.clear();
        int an=0,bn=0,cn=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            ans+=max(a[i],max(b[i],c[i]));
            if(a[i]>=b[i]&&a[i]>=c[i]){
                an++;
                va.push_back(min(a[i]-b[i],a[i]-c[i]));
            }else if(b[i]>=a[i]&&b[i]>=c[i]){
                bn++;
                vb.push_back(min(b[i]-a[i],b[i]-c[i]));
            }else{
                cn++;
                vc.push_back(min(c[i]-a[i],c[i]-b[i]));
            }
        }
        if(an>n/2){
            sort(va.begin(),va.end());
            for(int i=0;i<an-n/2;i++){
                ans-=va[i];
            }
        }else if(bn>n/2){
            sort(vb.begin(),vb.end());
            for(int i=0;i<bn-n/2;i++){
                ans-=vb[i];
            }

        }else if(cn>n/2){
            sort(vc.begin(),vc.end());
            for(int i=0;i<cn-n/2;i++){
                ans-=vc[i];
            }

        }

        cout<<ans<<endl;
    }
    return 0;
}
