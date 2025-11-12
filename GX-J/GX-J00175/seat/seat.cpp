#include <bits/stdc++.h>
using namespace std;
int n,m,b=0,c=0,r=0;;
int a[10000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n*m;i++){
        cin >> a[i];
    }
    b=a[0];
    for(int i=0;i<n*m-1;i++){
        for(int j=0;j<n*m-i-1;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=0;i<n*m;i++){
        if(a[i]==b){
            c=i;
            break;
        }
    }
    r=c%n;
    c/=n;
    if(c%2==0 && r!=0){
        cout << c+1 << " " << m-r+1;
    }else if(r==0){
        cout << c << " " << 1;
    }else if(c%2!=0){
        cout << c+1 << " " << r+1;
    }
    return 0;
}
