#include <bits/stdc++.h>
using namespace std;
const int tep=998244353;
int a[5005];
int main (){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    bool f=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)f=false;
    }
    if(n<=3){
        int x=a[1],y=a[2],z=a[3];
        if(x+y+z>max(max(x,y),z)*2)cout<<1<<endl;
        else cout<<0;
        return 0;
    }
    if(f){
        unsigned long long sum=1,f=1,f1=1;
        for(int i=1;i<=n;i++){
            sum=((sum%tep)*(2%tep))%tep;
        }
        for(int i=n;i>=1;i--){
            f=((f%tep)*(i%tep))%tep;
        }
        for(int i=n-2;i>=1;i--){
            f1=((f1%tep)*(i%tep))%tep;
        }
        f1=((f1%tep)*(2%tep))%tep;
        cout<<(sum-(f/f1)%tep-n-1)%tep;
        return 0;
    }
    return 0;
}
