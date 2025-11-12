#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[110];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++) cin>>b[i];
    int a1=b[0],a2=0;
    sort(b,b+n*m+1,cmp);
    for(int i=0;i<n*m;i++){
        if(b[i]==a1){
            a2=i+1;
            break;
        }
    }
    int ans1=ceil(a2*1.0/n*1.0);
    cout<<ans1<<" ";
    if(ans1%2==0){
            cout<<n+1-(a2-(ans1-1)*n);
        return 0;
    }
    else{
        cout<<a2-(ans1-1)*n;
    }
    return 0;
}
