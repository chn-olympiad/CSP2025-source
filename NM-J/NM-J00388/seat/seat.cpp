#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int a[1000];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int t = a[0];
    int b=  0;
    sort(a,a+n*m,cmp);
    for (int i=0;i<n*m;i++){
        if (t == a[i]){
            b = i+1;
            break;
        }
    }
    c = b/n;
    r = b%n;
    if (r != 0) c++;
    if (r == 0 && c%2==0) r=1;
    else if (r==0 && c%2==1) r =n;
    if (c%2==0 && r != 0){
        r = n-r+1;
    }
    cout<<c<<" "<<r<<endl;
    return 0;
}
