#include<bits/stdc++.h>
using namespace std;
int t,n,a[3][1000];
int z,s[3][1000];
int d(int m){
    int dd=0;
    if(a[0][m]>dd) dd=a[0][m],s[0][m]=1,s[1][m]=0,s[2][m]=0;
    if(a[1][m]>dd) dd=a[1][m],s[0][m]=0,s[1][m]=1,s[2][m]=0;
    if(a[2][m]>dd) dd=a[2][m],s[0][m]=0,s[1][m]=0,s[2][m]=1;
    z+=dd;
    return 0;
}
int j(int m){
    int a[1000];
    for(int i=0;i<n;i++){

    }
}
int qiou(){
    for(int i=0;i<n;i++){
        d(i);
    }
    for(int i=0,o=0;i<=2;i++,o=0){
        for(int f=0;f<n;f++){
            if(s[i][f]=1) o++;
        }
        if(o>n/2) j(i);
    }
    return z;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[0][i]>>a[1][i]>>a[2][i];
        }
        cout<<qiou();
    }
    return 0;
}
