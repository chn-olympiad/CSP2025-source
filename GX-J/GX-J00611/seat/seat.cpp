#include<bits/stdc++.h>
using namespace std;
int m,n,z,a;
bool cmp(int a,int b){
if(a>b){
return true;}
else{return false;
}}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>m>>n;
int i,j,f,w,s[m*n];
for(i=1;i<=m*n;i++){
    cin>>s[i];
}
z=s[1];
w=m*n;
sort(s[1],w,cmp)
for(i=1;i<=m;i++){
    a=i;
    for(j=1;j<=n;j++){
        if(s[j]==z){
                cout<<a<<z<<endl;
            break;
        }
    }
}
return 0;
}
