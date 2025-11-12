#include<bits/stdc++.h>
using namespace std;
int a1;
int ans;
int n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%d",&a1);
    for(int i=2;i<=n*m;i++){
        int x;
        scanf("%d",&x);
        if(x>a1)ans+=1;
    }
    cout<<ans/n+1<<" ";
    if((ans/n+1)%2==1)cout<<ans%n+1<<endl;
    else cout<<m-ans%n<<endl;
    return 0;
}
