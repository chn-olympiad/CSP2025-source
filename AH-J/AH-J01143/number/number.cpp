#include<bits/stdc++.h>
using namespace std;
int cnt[20];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	bool flag=false;
	for(int i=9;i>=0;i--){
		if(i==0&&flag==false){
			cout<<0;
			break;
		}
		for(int j=1;j<=cnt[i];j++){
			cout<<i;
			flag=true;
		}
	}
	return 0;
}
