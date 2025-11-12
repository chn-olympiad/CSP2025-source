#include<bits/stdc++.h>
using namespace std;
string s;
long long o,k;
char a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
cin>>s;
k=s.length();
for(int i=0;i<k;i++){
if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
o++;
a[o]=s[i];

}
}
sort(a+1,a+o+1);
for(int j=o;j>=1;j--)
cout<<a[j];
}
