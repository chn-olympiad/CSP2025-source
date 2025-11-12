#include<bits/stdc++.h>
using namespace std;
int a[165]={0};
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int s,d;
    cin>>s>>d;
    int n=s*d;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int w=a[0];
    sort(a,a+n);
    int p=0;
    if(d%2!=0){
        for(;p<s;p++){
            if(a[p]==w){
                cout<<d<<" "<<s-p;
            }
        }
    }
    for(int i=d-(d%2);i>0;i--){
        for(int j=1;j<=s;j++){
            if(a[p]==w)  cout<<i<<" "<<j;
            ++p;
        }
        --i;
        for(int j=s;j>0;j--){
            if(a[p]==w)  cout<<i<<" "<<j;
            ++p;
        }
    }
    return 0;
}

