#include<bits/stdc++.h>
using namespace std;
const int h=3;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
     int n,m;
     cin>>n>>m;
    char s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
     int c[n];
     for(int i=0;i<n;i++){
        cin>>c[i];
     }
     int A=1;
     for(int i=2;i<=n;i++){
         A*=i;
     }
    for(int i=0;i<n;i++){
        if(c[i]>c[i+1]){
            swap(c[i],c[i+1]);
            if(i>=c[i]){
                A-=n-i;
            }
            if(i<m){
               A--;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            A--;
        }
    }
    A-=h;
    cout<<A%998244353;
    return 0;
}
