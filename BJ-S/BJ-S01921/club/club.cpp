#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct e{
    int a1,a2,a3,b;
};
e num[N];

bool cmp(e x,e y){
    if(x.b!=y.b){
        return x.b>y.b;
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>num[i].a1>>num[i].a2>>num[i].a3;
            num[i].b=num[i].a1-num[i].a2;
        }
        sort(num+1,num+1+n,cmp);
        long long ans=0;
        for(int i=1;i<=(n/2);i++){
            ans+=num[i].a1;
        }
        for(int i=(n/2)+1;i<=n;i++){
            ans+=num[i].a2;
        }
        cout<<ans<<endl;
    }
    return 0;
}