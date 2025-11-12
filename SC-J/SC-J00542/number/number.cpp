#include<bits/stdc++.h>
using namespace std;
string s; 
int w;
int c[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;	
	if(s.length()==1){
		cout<<s;
		return 0;
	}
	int n=s.length();
	for(int i=0;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			c[w]=s[i]-48;
			++w;
		}
	}
	sort(c,c+w);
	for(int i=w-1;i>=0;i--){
		cout<<c[i]; 
	}
	return 0;
}