#include<bits/stdc++.h>
using namespace std;
int n,m,a[200];
int s[200];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        s[i]=a[i];
    }
    sort(s+1,s+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(s[i]==a[1]){
            if(i%n==0)cout<<i/n<<" ";
            else cout<<(i/n)+1<<" ";
            if(i%n==0){
                if((i/n)%2==1)cout<<n;
                else cout<<1;
            }
            else {
                if(i/n%2==1)cout<<n-i%n+1;
                else cout<<i%n;
            }
            return 0;
        }

    }
    return 0;
}
