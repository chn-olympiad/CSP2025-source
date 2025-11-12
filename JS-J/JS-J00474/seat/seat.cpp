#include <bits/stdc++.h>
using namespace std;
const int N=13;
int a[114],m,n;
bool op=1;
bool cmp(int q,int w){
    return q>w;
    }
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++) cin>>a[i];
    int t=a[1],s;
    sort(a+1,a+m*n+1,cmp);
    for(int i=1;i<=m*n;i++) {
        if(a[i]==t) s=i;
    }
    if(s%n!=0){
        if((s/n+1)%2==1) cout<<s/n+1<<' '<<s%n;
        else cout<<s/n+1<<' '<<n+1-s%n;
    }else{
        if((s/n)%2==1) cout<<s/n<<' '<<n;
        else cout<<s/n<<' '<<1;
    }
    return 0;
}
