#include<iostream>
using namespace std;
int b[15];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			int num=s[i]-'0';
			b[num]++;
		}
	}
	bool flag=false;
	for(int i=9;i>=0;i--){
		if(i&&b[i]) flag=true;
		if(i==0&&!flag){
			if(b[0]) cout<<0;
			exit(0);
		}
		for(int j=1;j<=b[i];j++) cout<<i;
	}
	return 0;
}
