#include<bits/stdc++.h>
using namespace std;
string s;
int nl=0;
char c[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a=s.size();
	for(int i=0;i<a;i++){
		if(s[i]>='0'&&s[i]<='9')c[++nl]=s[i];
	}
	sort(c+1,c+1+nl);
	for(int i=nl;i>=1;i--)cout<<c[i];
	return 0;
}
