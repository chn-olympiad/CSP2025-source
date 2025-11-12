#include <bits/stdc++.h>
using namespace std;

long long k,n,a[500010]={0},b[500010]={0},x=0,ss=0;
int xray(int z,int y){
    int ss=a[z];
    if(z<y){
    for(int i=z+1;i<=y;i++){
        ss=(ss^a[i]);
    }
    return ss;
    }
    else{
        return ss;
    }
}
bool y(int z,int y){
    for(int i=z;i<=y;i++){
        if(b[i]==1){
            return false;
        }
    }
    return true;
}
void yh(int z,int y){
    for(int i=z;i<=y;i++){
        b[i]=1;
    }
}

int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=1;i<=n;i++){
    for(int i2=0;i2<n;i2++){
        if(xray(i2,i2+i-1)==k&&y(i2,i2+i-1)){
           ss++;
           yh(i2,i2+i-1);
        }
    }
}
cout<<ss;

return 0;
}
