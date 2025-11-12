#include<bits/stdc++.h>
using namespace std;
int n,t;
struct T{
    int c1,c2,c3;
}a[100010];
bool cmp(T x,T y){
    return x.c1>y.c1;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
     //   if(n==100000){
            for(int i=1;i<=n;i++){
                scanf("%d%d%d",&a[i].c1,&a[i].c2,&a[i].c3);
            }
            sort(a+1,a+n+1,cmp);
            long long ans=0;
            for(int i=1;i<=n/2;i++){
                ans+=a[i].c1;
            }
            cout<<ans<<endl;
     //   }
    }
    return 0;
}
