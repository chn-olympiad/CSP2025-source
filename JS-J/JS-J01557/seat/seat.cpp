#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,r,index;
    cin>>n>>m;
    cin>>r;
    a[0]=r;
    for(int i=1;i<m*n;i++){
        cin>>a[i];
    }
    sort(a,a+n*m,greater<int>());
    for(int i=0;i<n*m;i++){
        if(a[i]==r){
            index=i;
            break;
        }
    }
    int hang,lie;
    lie=index/n+1;
    if(lie%2==0){
        hang=n-(index-(lie-1)*n);
        cout<<lie<<' '<<hang;
    }
    else{
        hang=index-(lie-1)*n+1;
        cout<<lie<<' '<<hang;
    }
    return 0;
}
