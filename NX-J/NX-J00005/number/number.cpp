#include <bits/stdc++.h>
using namespace std;
char a[100001];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string b;
cin>>b;
int x=b.length();
for(int i=0;i<x;i++)
    a[i]=b[i];
for(int i=0;i<x;i++){
    for(int j=1;j<x;j++){
        if(a[j]>a[j-1])
            swap(a[j],a[j-1]);
    }
}
for(int i=0;i<x;i++)
{
    if(isdigit(a[i]))
        cout<<a[i];
}
return 0;
}
