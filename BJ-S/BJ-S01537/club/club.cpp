#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+10;
int t;
ll n,res;
struct stu{
    ll a1,a2,a3;
}a[N];
bool cmp(stu x,stu y){
    return x.a1>y.a1;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
        }
        sort(a+1,a+n+1,cmp);

        for(int i=1;i<=n/2;i++){
           res+=a[i].a1;
        }
        cout<<res<<endl;
        res=0;
    }

    return 0;
}
