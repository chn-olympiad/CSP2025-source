#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=15;
int n,m,a[N*N],q;
bool cmp(int q,int b){
    return q>b;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int q=a[1];
    sort(a+1,a+1+n*m,cmp);
    int st=0;
    for(int i=1;i<=n*m;i++)if(a[i]==q){st=i;break;}
    //cout<<st<<endl;
    int h=ceil(1.0*st/n);
    if(h&1){
        if(st%n==0)cout<<h<<" "<<n<<endl;
        else cout<<h<<" "<<st%n;
    }else{
        int g=st%n;
        if(g==0)g=n;
        cout<<h<<" "<<n-g+1;
    }
        /*
    int h=ceil(st/n);
    int g=0;
    bool f=0;
    for(int i=1;i<=n*m;i+=2*n){
        if(st>=i&&st<=i+2*n-1){
            for(int j=i;j<=i+n-1;j++){
                if(a[j]==q){
                    g=j-i+1;
                    f=1;
                    break;
                }
            }
            if(f)break;
            for(int j=i+2*n-1;j>=i+n+1;j--){
                if(a[j]==q){
                    g=j-(i+1)+1;
                    q=1;
                    break;
                }
            }
        }
        if(f)break;
    }
    */
    //cout<<h<<" "<<g<<endl;
    return 0;
}
//100 97
//99  98
