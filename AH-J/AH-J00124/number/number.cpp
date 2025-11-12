#include<bits/stdc++.h>
using namespace std;
string s;
int c[1000000];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
int j=0;
for(int i=0;i<s.size();i++){
    if(s[i]>='0'&&s[i]<='9'){
        c[j]=s[i]-'0';
        j++;

    }
}
sort(c,c+j);
for(int i=j-1;i>=0;i--){
    cout<<c[i];
}
cout<<endl;
return 0;
}
