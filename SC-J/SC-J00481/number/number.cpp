#include<bits/stdc++.h>
using namespace std;
char ans[1000005];
string s;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	//cout << s.size() << endl << s << endl;
	int cur=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cur++;
			ans[cur]=s[i];
		}
	}
	//cout << cur << endl;
	//ans[1]='a';
	sort(ans+1,ans+cur+1,cmp);
	for(int i=1;i<=cur;i++){
		cout<<ans[i];
	}
	return 0;
}