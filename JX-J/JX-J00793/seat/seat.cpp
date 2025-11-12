#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[100000];
    cin>>n>>m;
    cin>>a[1];
    int jl = a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    int jl2=1;
    for(int i=1;i<=n*m;i++){
        if(jl == a[i]){
            break;
        }
        jl2++;
    }
    int r = jl2%n;
    if(r == 0){
        r = n;
    }
    int c=1;
    while(true){
        jl2 = jl2-3;
        if(jl2<0){
            break;
        }
        c++;

    }
    if(c%2==0){
        r = n-r+1;       
    }
    cout<<c<<" "<<r;
    return 0;
} 