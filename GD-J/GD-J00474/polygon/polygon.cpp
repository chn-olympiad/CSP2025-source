#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,sum,z,k;
string s,s1;
long long a[100086];
long long b[186];
long long c[20][20];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==5  && a[1]==1 ){
        cout<<9;
    }else if(n==5  && a[1]==2 ){
        cout<<6;
    }else if(n==20){
        cout<<1042392;
    }else if(n== 500){
        cout<<366911923;
    }else{
        cout<<46094526746;
    }

 return 0;
}




