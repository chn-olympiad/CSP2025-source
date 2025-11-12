#include<bits/stdc++.h>
using namespace std;
int n,k,x,y,a,b;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++){
    cin>>a;
    if(a==0){
        x++;
        x=b/2+x;
        b=0;
    }
    else{
        y++;
        b++;
    }
}
if(k==0){
    cout<<x;
}
else{
    cout<<y;
}
}
