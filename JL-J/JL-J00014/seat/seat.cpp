#include "bits/stdc++.h"
using namespace std;
bool a[99];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int m,n;
    cin>>m>>n;
    int a1;
    cin>>a1;
    for(int i=0;i<m*n;i++){
        int b;
        cin>>b;
        a[b-1]=1;
    }
    a[a1-1]=1;
    int paiming=0;
    for(int i=0;i<100;i++){
        if(i>a1-1&&a[i]==1){
            paiming++;
        }
    }

    int c,r;
    c=paiming/n;

    string s;
    for(int i=0;i<n;i++){
        s+=(i+48);
    }
    for(int i=n-1;i>=0;i--){
         s+=(i+48);
    }
    //cout<<"s:"<<s<<endl;

    r=s[paiming%s.size()]-48;

    cout<<c+1<<" "<<r+1;
    return 0;
}

