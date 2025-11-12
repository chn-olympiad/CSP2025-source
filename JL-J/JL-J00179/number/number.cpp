#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
boat(int cmp,int a,int b){
return a>b;
}
int j=0;
cin>>s;
for(int i=0;i<s.size();i++){
if(s[i]>=0)
{
    a[j]=s[i]-'0';
    j++;
}
}
sort(a,a+j,cmp);
for(int i=0;i<j;i++)
{
    cout<<a[i];
}
return 0;
}

