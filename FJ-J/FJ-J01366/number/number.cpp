#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
char s[N];
int n,f[20];
bool o=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>(s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if('0'<=s[i]&&s[i]<='9'){
			f[s[i]-'0']++;
			if(s[i]!='0')
				o=1;}
	if(!o)
		cout<<0<<endl;
	else{
		for(int i=9;i>=0;i--)
			for(int j=1;j<=f[i];j++)
				cout<<i;
		cout<<endl;}
	return 0;
} 
