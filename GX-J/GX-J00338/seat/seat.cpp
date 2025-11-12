#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define c(x) cout<<x<<"<"<<endl
using namespace std;
int n,m,nm;
int a[500];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m; nm=n*m;
    for(int i=0;i<nm;i++) cin>>a[i];
    int R=a[0],Rid=-1;
    sort(a,a+nm);
    for(int i=0;i<nm;i++)
        if(a[i]==R){
            Rid=nm-i; break;
        }
    int ans1=ceil(1.0*Rid/n),ans2;
    if(ans1%2){
        ans2=Rid-(ans1-1)*n;
    }else ans2=n-(Rid-(ans1-1)*n-1);
    cout<<ans1<<" "<<ans2;
    return 0;
}
