#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int l,int r){
    return l>r;
}
int n,m,a[110],num,x=1,y=1;
signed main(){
    freopen("text.in","r",stdin);
    freopen("text.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1) num=a[i];
    }
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(num==a[i]){
            num=i;
            break;
        }
    }
    for(int i=2;i<=num;i++){
        if(y%2==1){
            if(x+1<=n) x++;
            else y++;
        }
        else{
            if(x-1>=1) x--;
            else y++;
        }
    }
    cout<<y<<" "<<x;
    return 0;
}
