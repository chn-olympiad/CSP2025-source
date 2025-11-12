#include<bits/stdc++.h>
using namespace std;
string s;
char c;
int a[10000010];
int k,sl;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	sl=s.size();
	while(sl){
		c=s[sl-1];
		if(c>='0'&&c<='9'){
			k++;
			a[k]=int(c)-48;
		}
		sl--;
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
