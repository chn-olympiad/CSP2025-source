#include<bits/stdc++.h> 
using namespace std;
long long n,a[20];
string s;
int main(){
	freopen("number.ans","r",stdin);
	freopen("number.ans","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<char(i+'0');
		}
	}
	return 0;
}
