#include<bits/stdc++.h>
using namespace std;
char c[1000001];
int k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9') c[++k]=s[i];
	}
	sort(c+1,c+k+1);
	for(int i=k;i>=1;i--) cout<<c[i];
	return 0;
}
