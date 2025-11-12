#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string a;
cin>>a;
int s[1100000]={0},j=0;
for(int i=0;i<a.size();i++)
{
    if(a[i]>='0'&&a[i]<='9'){

        s[j]=int(a[i]-'0');
                j++;
    }
}

sort(s,s+j);
for(int i=j-1;i>=0;i--){
    cout<<s[i];
}
return 0;}
