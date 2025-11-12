#include<bits/stdc++.h>
using namespace std;
int ha[10];
bool vis[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			int id=s[i]-'0';
			ha[id]++;
		}
	}
	for(int i=0;i<=9;i++){
		if(ha[i]!=0){
			vis[i]=true;
		}
	}
	if(!vis[1]&&!vis[2]&&!vis[3]&&!vis[4]&&!vis[5]&&!vis[6]&&!vis[7]&&!vis[8]&&!vis[9]&&vis[0]){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=ha[i];j++){
			cout<<i;
		}
	}
	return 0;
}
