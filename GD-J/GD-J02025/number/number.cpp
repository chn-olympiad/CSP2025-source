#include<bits/stdc++.h>
using namespace std;
long long num[10]={0};
string s;

int main(){
	freopen("number1.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++){
			cout<<i;
		}
	}
	cout<<"\n";
	return 0;
} 
