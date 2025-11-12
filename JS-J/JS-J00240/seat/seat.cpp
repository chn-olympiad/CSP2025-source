#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }int ans1=a[0],ans2;
    sort(a,a+n*m,cmp);
    for(int i=0;i<n*m;i++){
        if(a[i]==ans1){
            ans2=i;
            break;
        }
    }if(n==1){
        cout<<ans2+1<<" 1";
        return 0;
    }int nx=(ans2+1)/n;
    int ny=(ans2+1)-nx*n;
    if(nx%2==1&&ny!=0){
        cout<<nx+1<<" "<<n-ny+1;
        return 0;
    }else if(nx%2==0&&ny!=0){
        cout<<nx+1<<" "<<ny;
        return 0;
    }else if(nx%2==1&&ny==0){
        cout<<nx<<" "<<n;
        return 0;
    }else if(nx%2==0&&ny==0){
        cout<<nx<<" 1";
        return 0;
    }
    return 0;
}
