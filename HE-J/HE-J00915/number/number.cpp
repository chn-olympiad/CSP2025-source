#include <bits/stdc++.h>
using namespace std;
string s,t;
long long ans,a=1;
int main(){


freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
for(int i=0;i<s.size();i++){
    if(s[i]-'0'>=0 && s[i]-'0'<=9){
    	t+=s[i];
}
}
long long shu[t.size()];
for(int i=0;i< t.size();i++){
	shu[i]=t[i]-'0';
}

sort(shu,shu+t.size());
for(int i=0;i<t.size();i++){
ans+=shu[i]*a;
if(a==1)a=10;
else a*=10;
}
cout<<ans;
return 0;
}
