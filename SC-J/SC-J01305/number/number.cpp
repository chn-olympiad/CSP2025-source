#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s=' '+s;
	for(int i=1;i<s.size();i++)
	{
		if(s[i]-48<=9){
			a[++cnt]=s[i]-48;
		}
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 