#include <bits/stdc++.h>
using namespace std;
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int main(){
    char a,b,c=' ',d=' ';
    scarf("%c%c",&a,&b)
    if(a>47&&a<65)c=a;
    if(b>47&&b<65)d=b;
    if(d>1&&c>1){
        if(c>=d)cout<<c<<d;
        if(d>c)cout<<d<<c;
    }else if(c>1)cont<<c;
    else cout<<d;

   return 0;
}
