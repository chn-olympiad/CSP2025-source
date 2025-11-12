#include<bits/stdc++.h>
using namespace std;
//const int N=1e9+4;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	long cnt=0;
	long a[s.length()];
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++cnt]=(int)(s[i]-'0');
		}
		
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--)cout<<a[i];
	return 0;
}
