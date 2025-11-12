#include <bits/stdc++.h>
using namespace std;
int a[110];
bool com(int a,int b){
    if(a>b){
        return true;
    }
    return false;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,p;
    cin >> n >> m;
    for(int i = 0;i<n*m;i++){
        cin >> a[i];
    }
    p=a[0];
    sort(a,a+n*m,com);
    int s;
    for(int i = 0;i<n*m;i++){
        if(a[i]==p){
            s=i+1;
            break;
        }
    }
    int c,r;
    c=ceil(s/1.0/n);
    if(c%2==1){
        r=s%n;
        if(r==0)
            r=n;
        cout << c << ' ' << r << endl;
    }
    else{
        r=n-s%n+1;
        if(s%n==0){
            r=1;
        }
        cout << c << ' ' << r << endl;
    }
    return 0;
}

