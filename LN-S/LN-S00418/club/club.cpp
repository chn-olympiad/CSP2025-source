#include <bits/stdc++.h>
using namespace std;
int n,t;

long long a[100005][5],ans ;
long long b[100005];

void work(int a1,int a2,int a3,long long k,int m){
    if(a1<n/2)work(a1+1,a2,a3,k+a[m][0],m+1);
    if(a2<n/2)work(a1,a2+1,a3,k+a[m][1],m+1);
    if(a3<n/2)work(a1,a2,a3+1,k+a[m][2],m+1);
    if(m==n)ans=max(ans,k);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=30){
            for(int i=0;i<n;i++){
                cin>>a[i][0]>>a[i][1]>>a[i][2];
            }
            work(0,0,0,0,0);cout<<ans<<endl;
            ans=0;
        }
        else{
            for(int i=0;i<n;i++){
                int x,y,z;cin>>x>>y>>z;
                b[i]=x;
            }
            sort(b,b+n);
            for(int i=n-1;i>=n/2;i--)ans+=b[i];
            cout<<ans;ans=0;
        }
    }return 0;
}
