#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100010],b[100010],c[100010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int cnt=n/2,ans=0;
        for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
        for(int i=1;i<=n;i++){
            if(a[i]>b[i]&&a[i]>c[i])ans+=a[i];
            else if(b[i]>a[i]&&b[i]>c[i])ans+=b[i];
            else ans+=c[i];
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
