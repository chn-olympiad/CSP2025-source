#include <bits/stdc++.h>
using namespace std;
int cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ans="";
	int n=0;
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			cnt[s[i]]++;
			n++;
		}
	}int a=0;
	for(int j=9;j>=0;j++){
		if(cnt[j]<=a){
			continue;
		}else{
		for(int k=a;k<=a+cnt[j];k++){
			cout<<cnt[j];
		}a++;
		}
	}
	return 0;
}//helppppppp
