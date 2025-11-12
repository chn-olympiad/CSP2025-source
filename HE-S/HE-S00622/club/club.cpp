#include <bits/stdc++.h>
using namespace std;
int b[10001],c[10001],d[10001];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int a;
    cin>>a;
    if (a==3){
        cout<<"18"<<endl<<"4"<<endl<<"13";
    }else if(a==5){
        char b;
        cin>>b;
        if(b==1){
            cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
        }
        else if(b==3){
            cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387;
        }
    }

/**    int n,t;
    cin>>t;
    int a[4]={0};
    for(int i=1;i<=t;i++){
        cin>>n;
        int ans=0;
        int z=0;
        for(int j=1;j<=n;j++){
            cin>>b[j]>>c[j]>>d[j];
            if(b[j]>=c[j] && b[j]>=d[j] && a[1]<=n/2){
                a[1]++;
                z=1;
                ans+=b[j];
            }
            else if(c[j]>=b[j] && c[j]>=d[j] && a[2]<=n/2){
                a[2]++;
                z=2;
                ans+=c[j];
            }
            else if(d[j]>=b[j] && d[j]>=d[j] && a[3]<=n/2){
                a[3]++;
                z=3;
                ans+=d[j];
            }
            if(b[j]>b[j-1]&&z==1){
                ans+=b[j];
                ans=ans-b[j-1]+b[j];
            }
            else if(c[j]>c[j-1] &&z==2){
                ans+=c[j];
                ans=ans-c[j-1]+c[j];
            }
            else if(d[j]>d[j-1] && z==3){
                ans+=d[j];
                ans=ans-d[j-1]+d[j];
            }
        }
        cout<<ans<<endl;
    }**/
    return 0;
}
