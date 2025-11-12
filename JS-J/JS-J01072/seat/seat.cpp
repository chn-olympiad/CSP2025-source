#include <bits/stdc++.h>
using namespace std;
int n,m,a[10086];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n*m; i++){
        cin>>a[i];
    }int num=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1; i<=n*m/2; i++){
        swap(a[i],a[n*m-i+1]);
    }for(int i=1; i<=n*m; i++){
        if(a[i]==num){
            int l=i/n;
            if(i%n!=0) l++;
            int h;
            if(l%2==1) h=i-(l-1)*n;
            else h=n-(i-(l-1)*n)+1;
            cout<<l<<" "<<h;
        }

    }return 0;
}
