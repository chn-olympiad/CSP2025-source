#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int num[10];
	cin>>s;
	int l=s.size();
	for(int i=0;i<10;i++){
		num[i]=0;
	}
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']+=1;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<num[i];j++){
			cout<<i;
		}
	}
	return 0;
}