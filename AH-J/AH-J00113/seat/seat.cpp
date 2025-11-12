#include<bits/stdc++.h>
int a[105],s,b[11][11];
bool cmp(int a,int b){
return a>b;
}
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=0;i<n*m;i++){
        cin>>a[i];
}
int s=a[0];
int t=0,ai=-1;
sort(a,a+n*m,cmp);
for(int j=0;j<m;j++){
    for(int i=0;i<n;i++){
        ai++;
        if(t%2==1){
            b[j][n-i-1]=a[ai];
        }else{
            b[j][i]=a[ai];
        }
    }
    t++;
}
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(s==b[j][i]){
            cout<<j+1<<" "<<i+1;
            return 0;
        }
    }
}
return 0;
}
