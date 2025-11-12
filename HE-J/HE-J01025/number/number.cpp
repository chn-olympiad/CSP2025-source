#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	string s;
	int a[10]={0};
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;){
		if(a[i]==0){
			i--;
		}
		else{
			a[i]--;
			cout<<i;
		}
	}
	return 0;
} 
