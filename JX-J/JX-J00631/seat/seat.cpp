#include <bits/stdc++.h>
using namespace std;
int t[110],n,m,r,s,h,l;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++) cin>>t[i];
    r = t[1];
    sort(t+1,t+n*m+1,cmp);
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                s++;
                if(t[s]==r){
                    h=j;
                    l=i;
                    break;
                }
            }
        }else{
             for(int j=m;j>=1;j--){
                s++;
                if(t[s]==r){
                    h=j;
                    l=i;
                    break;
                }
            }
        }
        if(h!=0&&l!=0) break;
    }
    cout<<l<<' '<<h;
    return 0;
}
