#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int x,cnt=1,tmp;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>x;
    for(int i=1;i<n*m;i++){
        cin>>tmp;
        if(x<tmp){
            cnt++;
        }
    }
    if(((cnt+n-1)/n)%2==1){
        cout<<(cnt+n-1)/n<<' '<<((cnt%n)==0 ? n :cnt%n);
    }
    else{
        cout<<(cnt+n-1)/n<<" "<<n-((cnt%n)==0 ? n :cnt%n)+1;
    }
    return 0;
}