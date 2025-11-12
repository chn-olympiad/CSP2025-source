#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int s=n*m;
    cin>>a[1];
    int t=a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+s,cmp);
    if(a[1]==t){
        cout<<1<<" "<<1;
        return 0;
    }
    int l=1,r=1,i=2;
    bool f=1;
    while(1){
        if(f==1){
            if(r+1<=n){
                r++;
            }else{
                l++;
                f=0;
            }
        }else{
            if(r-1>=1){
                r--;
            }else{
                l++;
                f=1;
            }
        }
        if(a[i]==t){
            cout<<l<<" "<<r;
            return 0;
        }
        i++;
    }
    return 0;
}
