#include<bits/stdc++.h>
using namespace std;
int a[50050];
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int n,k;
cin>>n>>k;
for(int i=0;i<n;i++){
    cin>>a[i];
}
int ma=0;
for(int u=0;u<n;u++){
int c=a[u],m=0;
for(int i=u,j=u;j<n;j++){
        if(c==k){
            j++;
            i=j;
            c=a[i];
            m++;
        if(c==k&&j==n-1){
            m++;
            }
        }else if(i!=j){
        c=c^a[j];
        if(c==k&&j==n-1){
            m++;
            }
        }
}
ma=max(ma,m);
}
cout<<ma;
return 0;
}
