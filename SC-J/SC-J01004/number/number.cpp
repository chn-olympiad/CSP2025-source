#include<bits/stdc++.h>
using namespace std;
string s;
int w,b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[++w]=s[i];
		}
	}
	sort(b+1,b+w+1);
	for(int i=w;i>=1;i--){
		cout<<(char)b[i];
	}
	return 0;
}