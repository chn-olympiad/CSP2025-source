#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[10]={};
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int y=1;y<=a[i];y++){
			cout<<i;
		}
	}
	return 0;
} 