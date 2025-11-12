#include<bits/stdc++.h>
using namespace std;
int n,m,tot,a[105],b,c,ans1,ans2;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    tot=n*m;
    for(int i=1;i<=tot;i++){
        cin>>a[i];
    }
    b=a[1];
    sort(a+1,a+tot+1);
    for(int i=1;i<=tot;i++){
        if(a[i]==b)c=tot-i+1;
    }
    ans1=(c+n-1)/n;
    if(ans1%2==1)ans2=(c-1)%n+1;
    else ans2=n+1-((c-1)%n+1);
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
