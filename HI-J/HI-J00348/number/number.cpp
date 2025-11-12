#include<bits/stdc++.h>
using namespace std;
string s;
char x[1010];
long long m=0;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>s;
	if(s.size()==1&&(s[0]>='0'&&s[0]<='9')){
		cout<<s[0];
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			x[m]=s[i];
			m++;
		}
	}
	sort(x,x+m);
	for(int i=m-1;i>=0;i--){
		cout<<x[i];
	}
	return 0;
}

