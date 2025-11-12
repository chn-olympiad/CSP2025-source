#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n[1005],m[1005],a,b,r,h,l;
cin>>a>>b;
for(int i=1;i<=a*b;i++){
    cin>>n[i];
}
r=1;
for(int i=1;i<=a*b;i++){
    if(n[i]>n[1]){
        r++;
    }
}
h=r%a;
if(h==0){
        l=r/a;
    if(l%2==0)
        cout<<l<<" "<<1;
    else
        cout<<l<<" "<<a;
}
else{
    l=r/a+1;
        if(l%2==0)
            cout<<l<<" "<<a-h+1;

        else
            cout<<l<<" "<<h;
}

return 0;
}

