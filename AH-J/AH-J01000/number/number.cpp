#include<bits/stdc++.h>
using namespace std;
int sum[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;s[i];i++){
		if(s[i]>='0'&&s[i]<='9') sum[s[i]-'0']++;
	}
	s="";
	for(int i=9;i>=0;i--){
		for(int j=1;j<=sum[i];j++){
			s+=('0'+i);
		}
	}
	cout<<s;
	return 0;
}
