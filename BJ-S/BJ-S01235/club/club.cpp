#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int j=1;j<=t;j++){
        int n;
            cin>>n;
        if(n==2){
            int a,b,c,d,e,f;
            cin>>a>>b>>c>>d>>e>>f;
            cout<<max(a+f,max(a+e,max(b+d,max(b+f,max(c+d,c+e)))))<<endl;
        }else{
        int flag=1;
        int a[100005],b[100005],c[100005];
        long long int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]!=0 or c[i]!=0){
                flag=0;
            }
        }
        if(flag==1){
            sort(a,a+n+1);
            for(int i=n/2+1;i<=n;i++){
                ans+=a[i];
            }
            cout<<ans<<endl;
        }else{
            for(int i=1;i<=n;i++){
                ans+=max(a[i],max(b[i],c[i]));
            }
            cout<<ans<<endl;
        }
        }
    }
    return 0;
}
