#include<bits/stdc++.h>
using namespace std;
string s,c;
long long i,a[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<=s.size();i++){
		if(s[i]=='0')a[0]++;
		if(s[i]=='1')a[1]++;
		if(s[i]=='2')a[2]++;
		if(s[i]=='3')a[3]++;
		if(s[i]=='4')a[4]++;
		if(s[i]=='5')a[5]++;
		if(s[i]=='6')a[6]++;
		if(s[i]=='7')a[7]++;
		if(s[i]=='8')a[8]++;
		if(s[i]=='9')a[9]++;
	}
	for(i=1;i<=a[9];i++)c=c+'9';
	for(i=1;i<=a[8];i++)c=c+'8';
	for(i=1;i<=a[7];i++)c=c+'7';
	for(i=1;i<=a[6];i++)c=c+'6';
	for(i=1;i<=a[5];i++)c=c+'5';
	for(i=1;i<=a[4];i++)c=c+'4';
	for(i=1;i<=a[3];i++)c=c+'3';
	for(i=1;i<=a[2];i++)c=c+'2';
	for(i=1;i<=a[1];i++)c=c+'1';
	if(a[1]||a[2]||a[3]||a[4]||a[5]||a[6]||a[7]||a[8]||a[9])for(i=1;i<=a[0];i++)c=c+'0';
	cout<<c;
}
