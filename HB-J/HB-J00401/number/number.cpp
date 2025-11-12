#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char ch[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int ln=s.size();	
	for(int i=0;i<ln;i++){
		if(s[i]>='a' && s[i]<='z'){
			continue;
		}
		else{
			ch[i]=s[i];
		}
	}
	sort(ch+1,ch+1+ln);
	for(int i=ln;i>=0;i--){
		cout<<ch[i];
		}
	return 0;
}
