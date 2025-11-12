#include <bits/stdc++.h>
using namespace std;
int cnt[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	bool f=1;
	for(int i=9;i>=0;i--){
		if(i!=0){
			if(cnt[i]!=0){
				f=0;
				for(int j=1;j<=cnt[i];j++){
					cout<<i;
				}
			}
		}
		else{
			if(f){
				cout<<0;
				return 0;
			}
			else{
				for(int j=1;j<=cnt[i];j++){
					cout<<i;
				}
			}
		}
	}
	return 0;
}
