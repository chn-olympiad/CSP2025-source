#include<bits/stdc++.h>
using namespace std;
struct S{
    int a,b,c,mx;
    int d;
}a[10005];
bool cmp(S a,S b){
    return a.d>b.d;
}
int n,t;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            int maxi=0;
            cin>>a[i].a>>a[i].b>>a[i].c;
            maxi=max(a[i].a,max(a[i].b,a[i].c));
            ans+=maxi;
            if(maxi==a[i].a){
                a[i].mx=1;
                a[i].d=min(maxi-a[i].b,maxi-a[i].c);
            }
            else if(maxi==a[i].b){
                a[i].mx=2;
                a[i].d=min(maxi-a[i].a,maxi-a[i].c);
            }
            else{
                a[i].mx=3;
                a[i].d=min(maxi-a[i].a,maxi-a[i].b);
            }
        }
        sort(a+1,a+n+1,cmp);
        int av[4]={0,n/2,n/2,n/2};
        for(int i=1;i<=n;i++){
            if(av[a[i].mx]>=1){
                av[a[i].mx]--;
            }
            else{
                ans-=a[i].d;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
