#include<bits/stdc++.h>
using namespace std;
string s;
int l;
int a[1000005];
int x;
int main(){
freopen("number.in","r",stdin);
freopen("number.ans","w",stdout);
cin>>s;
l=s.size();
for(int i=0;i<l;i++){
    if(s[i]>='0'&&s[i]<='9'){
        a[x]=s[i]-'0';
        x++;
    }
}
sort(a,a+x);
for(int i=x-1;i>=0;i--)cout<<a[i];

return 0;
}
//che(1) pai(2) ge(1) qu(4) si(3)
