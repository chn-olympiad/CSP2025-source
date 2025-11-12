#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 2e5 + 5;
int a[N][4],b[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n; cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
        if(n==2){
            int s1=a[1][1]+a[2][2];
            int s2=a[1][1]+a[2][3];
            int s3=a[1][2]+a[2][1];
            int s4=a[1][2]+a[2][3];
            int s5=a[1][3]+a[2][1];
            int s6=a[1][3]+a[2][2];
            int m1=max(s1,s2);
            int m2=max(s3,s4);
            int m3=max(s5,s6);
            cout<<max(m1,max(m2,m3))<<endl;
        }else{
            int sum=0;
            for(int i=1;i<=n;i++) b[i]=a[i][1];
            sort(b+1,b+n+1,greater<int>());
            for(int i=1;i<=n/2;i++) sum+=b[i];
            cout<<sum<<endl;
        }
    }
    return 0;
}
