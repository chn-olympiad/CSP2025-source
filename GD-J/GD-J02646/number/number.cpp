#include<bits/stdc++.h>
using namespace std;
bool cpp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int b[s.size()]={};
	int o=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[o]=s[i]-'0';
			o++;
		}
	}
	sort(b,b+o,cpp);
	for(int i=0;i<o;i++){
		if(i==0&&b[i]==0){
			cout<<0;
			break;
		}
		cout<<b[i];
	}
	return 0;
}
