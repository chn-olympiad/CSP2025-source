#include<bits/stdc++.h>
using namespace std;
string s;
string z;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
getline(cin,s);
int n=s.size();
for(int i=0;i<n;i++){
    if(s[i]>='0'&&s[i]<='9'){
        z[i]=s[i];
    }
}
for(int i=0;i<n;i++){
cout<<z[i];
}
return 0;
}
