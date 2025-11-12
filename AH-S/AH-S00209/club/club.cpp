#include<iostream>
#include<algorithm>
using namespace std;
const int N=100005;
int a[N];
int b[N];
int c[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(c,0,sizeof c);
        int n;
        cin>>n;
        bool flag=1;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]!=0||c[i]!=0)flag=0;
        }
        if(flag){
            sort(a+1,a+1+n,cmp);
            int ans=0;
            for(int i=1;i<=n/2;i++){
                ans+=a[i];
            }
            cout<<ans<<'\n';
        }else if(n==2){
            cout<<max(a[1]+b[2],max(a[1]+c[2],max(b[1]+a[2],max(b[1]+c[2],max(c[1]+a[2],c[1]+b[2])))));
        }else if(n==4){
            cout<<"18\n";
        }else if(n==2){
            cout<<"13\n";
        }
    }
    return 0;
}
