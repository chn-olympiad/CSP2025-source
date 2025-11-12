#include<bits/stdc++.h>
using namespace std;
string a;
int main(){

freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int nm[20];
memset(nm,0,sizeof(nm));
getline(cin,a);
for(int i = 0 ; i< a.size(); i++ )if((a[i]>='0')&&(a[i]<='9'))nm[a[i]-'0']++;

for(int i = 9 ; i>= 0 ; i--)
    for(int j = 0 ; j < nm[i];j++ )cout<<i;

cout<<endl;
return 0;
}
