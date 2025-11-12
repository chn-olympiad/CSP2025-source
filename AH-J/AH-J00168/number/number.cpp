#include<bits/stdc++.h>
using namespace std;
string s;
long long a[100];
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
s=" "+s;
int n=s.size();
for(int i=1;i<n;i++){
if('0'<=s[i]&&s[i]<='9')a[((int)s[i])-48]++;
}
for(int i=9;i>=0;i--){
for(int j=1;j<=a[i];j++){
cout<<i;	
}	
}
return 0;
}
