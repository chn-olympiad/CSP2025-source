#include<bits/stdc++.h>
using namespace std;
int a[200];
bool cmp(int aa,int bb){
    return aa>bb;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,num;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    num=a[1];
    int x=1,y=1,k=0;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(num==a[i]){
            k=i;
            break;
        }
    }
    while(1){
        k--;
        if(k==0){
            cout<<y<<' '<<x<<'\n';
            return 0;
        }
        if(y%2==1){
            if(x<n) x++;
            else y++;
        }
        else if(y%2==0){
            if(x>1) x--;
            else y++;
        }
    }
    return 0;
}
