#include <bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c;
    cin>>n>>m;
    for(int i=1;i<=(n*m);i++) cin>>a[i];
    c=a[1];
    sort(a+1,a+(n*m)+1);
    int t;
    for(int i=1;i<=n*m;i++){
        if(a[i]==c){
            t=n*m-i+1;
            break;
        }
    }
    int ans1=(t-1)/n+1,ans2=(t-1)%n+1;
    if(ans1%2==0) ans2=n-ans2+1;
    cout<<ans1<<" "<<ans2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
