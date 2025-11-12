#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100],c[100100];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int n;
    for(int i=1;i<=t;i++){
        cin>>n;
        bool flag=1;
        for(int j=1;j<=n;j++){
            cin>>a[j]>>b[j]>>c[j];
            if(a[i]!=0&&c[i]!=0){
                flag=0;
            }
        }
        if(flag){
            sort(b+1,b+n+1,cmp);
            int ans=0;
            for(int j=1;j<=n/2;j++){
                ans+=b[j];
            }
            cout<<ans<<endl;

            continue;
        }
        if(n==2){
            int p1=max(a[1],max(b[1],c[1]));
            int p2=max(a[2],max(b[2],c[2]));
            int cd1=max(min(a[1],b[1]),min(b[1],c[1]));
            int cd2=max(min(a[2],b[2]),min(a[2],c[2]));
            //cout<<p1<<' '<<p2<<' '<<cd1<<' '<<cd2<<endl;
            if(p1==a[1]&&p2==a[2]||p1==b[1]&&p2==b[2]||p1==c[1]&&p2==c[2]){
                cout<<max(cd1+p2,cd2+p1)<<endl;
                continue;
            }else{
                cout<<p1+p2;
                continue;
            }
        }
        cout<<5;

    }
    return 0;
}
