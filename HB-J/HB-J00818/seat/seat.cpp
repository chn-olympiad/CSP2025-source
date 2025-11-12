#include<bits/stdc++.h>
using namespace std;
int n,m;
int c=1,r=1;
int a1,a[105];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a1;
    for(int i=0;i<n*m-1;i++){
        cin>>a[i];
    }
    sort(a,a+n*m-1,greater<int>());
    for(int i=0;i<n*m-1;i++){
        if(a[i]<a1){
            break;
        }
        else{
            if(c%2){
                r++;
                if(r>n){
                    r--;
                    c++;
                }
            }
            else{
                r--;
                if(r<1){
                    r++;
                    c++;
                }
            }
        }
    }
    cout<<c<<' '<<r;
    return 0;
}
