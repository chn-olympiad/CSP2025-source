#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int s[105];
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    cin>>s[1];
    int t=s[1];
    for(int i=2;i<=n*m;i++){
        cin>>s[i];
    }
    sort(s+1,s+n*m+1,cmp);
    int pos=0;
    for(int i=1;i<=n*m;i++){
        if(t==s[i]){
            pos=i;
            break;
        }
    }
    int l1,l2=pos%n;
    if(l2==0){
        l1=pos/n;
    }else{
        l1=pos/n+1;
    }
    if(l1%2==1){
        if(l2==0){
            cout<<l1<<" "<<n;
        }else{
            cout<<l1<<" "<<l2;
        }
    }else{
        cout<<l1<<" "<<(n+1-l2)%4;
    }
    //cout<<" "<<pos;
    return 0;
}
