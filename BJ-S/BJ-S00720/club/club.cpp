#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n[10],a[100001][4];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        int c12=0,c5=0;
        cin>>n[i];
        for(int j=1;j<=n[i];j++){
            cin>>a[j][1]>>a[j][2]>>a[j][3];
            if(c12==0&&a[j][2]!=0)c12=1;
            if(c5==0&&a[j][3]!=0)c5=1;
        }
        if(n[i]==2){
            int ans=0;
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    if(i==j)continue;
                    else if(a[1][i]+a[2][j]>ans)ans=a[1][i]+a[2][j];
                }
            }
            cout<<ans;continue;
        }
        else if(c12==0){
            int ans=0,an[n[i]+1];
            for(int j=1;j<=n[i];j++)an[j]=a[j][1];
            sort(an+1,an+n[i]+1);
            for(int j=n[i];j>n[i]/2;j--)ans+=an[j];
            cout<<ans;continue;
        }
        else if(c12==1&&c5==0){
            int ans=0,an[n[i]+1],aaa=0,bbb=0;
            for(int j=1;j<=n[i];j++)aaa+=a[j][1];
            for(int j=1;j<=n[i];j++)bbb+=a[j][2];
            if(aaa>=bbb){
                for(int j=1;j<=n[i];j++)an[j]=a[j][1];
                sort(an+1,an+n[i]+1);
                for(int j=n[i];j>n[i]/2;j--)ans+=an[j];
                for(int j=n[i]/2;j>=1;j--)ans+=a[j][2];
                cout<<ans;continue;
            }
            else{
                for(int j=1;j<=n[i];j++)an[j]=a[j][2];
                sort(an+1,an+n[i]+1);
                for(int j=n[i];j>n[i]/2;j--)ans+=an[j];
                for(int j=n[i]/2;j>=1;j--)ans+=a[j][1];
                cout<<ans;continue;
            }
        }
    }
    return 0;
}
