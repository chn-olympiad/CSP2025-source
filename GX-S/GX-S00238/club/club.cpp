#include<bits/stdc++.h>
using namespace std;
int f1[60000],f2[60000],f3[60000],a[110000],b[110000],c[110000];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    for(int o=1;o<=t;o++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=n/2;j>=1;j--){
                f1[j]=max(f1[j]+max(b[i],c[i]),f1[j-1]+a[i]);
                f2[j]=max(f2[j]+max(a[i],c[i]),f2[j-1]+b[i]);
                f3[j]=max(f3[j]+max(b[i],a[i]),f3[j-1]+c[i]);
            }
            f1[0]=f1[0]+max(b[i],c[i]);
            f2[0]=f2[0]+max(a[i],c[i]);
            f3[0]=f3[0]+max(b[i],a[i]);
        }
        cout<<min(min(f1[n/2],f2[n/2]),f3[n/2])<<endl;
        fill(f1,f1+n/2+1,0);
        fill(f2,f2+n/2+1,0);
        fill(f3,f3+n/2+1,0);
    }
    return 0;
}
