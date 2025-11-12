#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
int cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')cnt[s[i]-'0']++;
	}
	bool flag=1;
	for(int i=9;i>=0;i--){
		if(cnt[i]&&i>0)flag=0;
		if(flag&&i==0){
			cout<<0;
			return 0;
		}
		for(int j=1;j<=cnt[i];j++)cout<<i;
	}
	return 0;
}

