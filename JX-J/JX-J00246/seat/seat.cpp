#include <bits/stdc++.h>
using namespace std;
int n,m,k,l,h;
int a[1020];
int s;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    k=a[1];
    sort(a+1,a+1+n*m,greater<int>());
    l=1,h=0,s=1;
    for(int i=1;i<=n*m;i++){
        h+=s;
        if(h>n||h<1){
            if(s==1)h=n;
            if(s==-1)h=1;
            l++;
            s*=-1;
        }
        if(a[i]==k){
            cout<<l<<" "<<h;
            return 0;
        }
    }
    return 0;
}
