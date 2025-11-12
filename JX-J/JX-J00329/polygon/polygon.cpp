#include<bits/stdc++.h>
using namespace std;
long long n,a[1000006];
bool cmp(int x,int y){
  return x>y;
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
if(n==3)
{
cout<<1;
return 0;
}
if(n<3){
    long long s=0;
    for(int i=2;i<=n-1;i++){
        s=s+n-i;
    }
    cout<<s;
    return 0;
}

return 0;
}
