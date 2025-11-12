#include <bits/stdc++.h>
using namespace std;
string a,b="";
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;int c=a.size();
    for(int i=0;i<c;i++) if(a[i]=='9') b=b+"9";
    for(int i=0;i<c;i++) if(a[i]=='8') b=b+"8";
    for(int i=0;i<c;i++) if(a[i]=='7') b=b+"7";
    for(int i=0;i<c;i++) if(a[i]=='6') b=b+"6";
    for(int i=0;i<c;i++) if(a[i]=='5') b=b+"5";
    for(int i=0;i<c;i++) if(a[i]=='4') b=b+"4";
    for(int i=0;i<c;i++) if(a[i]=='3') b=b+"3";
    for(int i=0;i<c;i++) if(a[i]=='2') b=b+"2";
    for(int i=0;i<c;i++) if(a[i]=='1') b=b+"1";
    for(int i=0;i<c;i++) if(a[i]=='0') b=b+"0";
    cout<<b;
    return 0;
}
