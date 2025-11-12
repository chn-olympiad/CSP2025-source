#include <bits/stdc++.h>
using namespace std;
string s;
int n,x[1000010];
bool c(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			x[n]=s[i]-'0';
			n++;
		}
	}
	sort(x,x+n,c);
	for(int i=0;i<n;i++){
		cout<<x[i];
	}
	return 0;
}
