#include <bits/stdc++.h>
using namespace std;
string b;
long long a[1000002],c,d=0,e=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>b;
    c=b.size();
    for(int i=1;i<=c;i++){
        a[i]=10;
    }
    for(int i=0;i<c;i++){
        if(b[i]-'0'<=9&&b[i]-'0'>=0){
            a[i+1]=b[i]-'0';
            d++;
        }
    }
    sort(a+1,a+c+1);
    for(int i=d;i>=1;i--){
        if(a[i]!=10){
            cout<<a[i];
        }
    }
    return 0;
}
