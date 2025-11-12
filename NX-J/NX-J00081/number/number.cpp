#include<bits/stdc++.h>
using namespace std;
bool f(int a,int b){
return a>b;
}
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s;
cin>>s;
int a[s.size()];
int p=0;
int ans=0;
for(int i=0;i<s.size();i++){
	if(s.at(i)>='0'&&s.at(i)<='9')a[p++]=s.at(i)-'0';
}
sort(a,a+p,f);
for(int i=0;i<p;i++)cout<<a[i];
return 0;
}
