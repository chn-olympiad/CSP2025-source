#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int a,b,T;
cin>>a>>b;
int c[a*b];
T=1;
for(int d=1;d<=a*b;d++)
    cin>>c[d];
for(int d=1;d<=a*b;d++){
    if(c[d]>c[1])
        T=T+1;
}

cout<<(T-1)/a+1<<" ";;
if(((T-1)/a)%2==0)
    cout<<(T-1)%a+1;
else cout<<a-((T-1)%a);
return 0;
}
