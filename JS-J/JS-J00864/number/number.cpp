#include<bits/stdc++.h>
using namespace std;
int a[1000005];
string s;
int main(){
freopen("number.in ","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
int l=s.size();
for(int i=0;i<l;i++){
if(s[i]>='0'&&a[i]<='9'){
a[i]=s[i]-'0';
	}
}
sort(a,a+l);
for(int i=0;i<l;i++){
cout<<a[i];
}
fclose(stdin);         
fclose(stdout);
return 0;
 }
