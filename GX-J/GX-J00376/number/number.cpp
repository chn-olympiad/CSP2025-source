#include <bits/stdc++.h>
using namespace std;
string s,z;
char b[100010];
int n,d,f;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
cin>>s;
n=s.size();
for (int i = 0; i < n; i++){
	if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
		b[d]=s[i];
		d++;
		}
}
sort(b,b+d+1);
	for (int i = d; i >0 ; i--)	{
		cout<<b[i];
	}
return 0;
}
