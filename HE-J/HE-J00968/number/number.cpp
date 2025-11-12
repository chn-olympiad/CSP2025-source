#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int cnt[20];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]>0){
			cout<<i;
			cnt[i]--;
		}
	}
//	system("fc number.out number4.ans");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
