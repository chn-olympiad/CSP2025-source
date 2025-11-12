#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int a[N],sum;
int cmp(int x,int y){return x>y;}
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s;
cin>>s;
int x=s.size();
s=" "+s;
for(int i=1;i<=x;i++){
    if(s[i]>='0'&&s[i]<='9'){
        a[++sum]=s[i]-'0';
    }
}
sort(a+1,a+sum+1,cmp);
if(a[1]==0){
    cout<<0;
    return 0;
}
for(int i=1;i<=sum;i++){
    cout<<a[i];
}
 return 0;
}
