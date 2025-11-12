#include<bits/stdc++.h>
using namespace std;
int a[1001];
int n,m,q,mr,nr;
int main(){
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    cin >> n >> m ;
    for(int i = 0 ; i < n*m ; i++){
        cin >> a[i];
    }
    int r = a[0];
    for(int p = 0 ; p < 6 ; p++){
        for(int i = 0 ; i < n*m-2 ; i++){
            if(a[i]<a[i+1]) swap(a[i],a[i+1]);
        }
    }
    int t = 0;
    for(int i = 0 ; i<n*m;i++){
        if(r == a[i]){
            t = i+1;
            break;
        }
    }
    if(t%n!=0) mr = (t/n)+1;
    else mr = t/n;
    if(mr%2==0) nr = n+1-(t-(mr-1)*n);
    else nr = (t-(mr-1)*n);
    cout<<mr<<' '<<nr;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
