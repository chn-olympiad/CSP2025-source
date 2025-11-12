#include<bits/stdc++.h>
using namespace std;
int number[12];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<int(s.size());i++){
		if(s[i]>='0'&&s[i]<='9') number[s[i]-'0']++;
	}
	bool flag=1;
	for(int i=9;i>=0;i--){
		for(int j=0;j<number[i];j++){
			if(i==0&&flag){
				cout<<0;
				break;
			}
			cout<<i;
		}
		if(number[i]>0) flag=0;
	}
	if(flag) cout<<0;
	return 0;
}
