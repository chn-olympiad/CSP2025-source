#include<bits/stdc++.h>
#define int long long
#define mes(x,y) memset(x,y,sizeof(x))
using namespace std;
int a[100005];
bool cmp(int i,int j){return i>j;}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;cin>>T;
    while(T--){
        mes(a,0);
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            int p,q;cin>>p>>q;
        }
        sort(a+1,a+1+n,cmp);
        int sum=0;
        for(int i=1;i<=n/2;i++){
            sum+=a[i];
        }
        cout<<sum<<'\n';
    }
    return 0;
}
//A:a[i][2]=a[i][3]=0
