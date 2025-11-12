#include<bits/stdc++.h>
using namespace std;
string s;
int b[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a=s.size(),j=0;
	for(int i=0;i<a;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[j++]=s[i]-'0';
		}
	}
	sort(b,b+j);
	for(int i=j-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}