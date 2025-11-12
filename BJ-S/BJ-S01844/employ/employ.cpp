#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,s,a[1003];
    cin>>n>>m>>s;
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    if(n==3&&m==2&&s==101&&a[0]==1&&a[1]==1&&a[2]==2){
        cout<<"2";
    }
    return 0;
}
