#include<bits/stdc++.h>
using namespace std;
int ans[1000005],ai;
string s;
bool cmp(int xx,int yy){
	return xx>yy;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int n=s.size();
	for(int i = 0; i < n; ++i){
		if(s[i]>='0' && s[i]<='9'){
			ans[++ai]=s[i]-'0';
		}
	}
	sort(ans+1,ans+ai+1,cmp);
	for(int i = 1; i <= ai; ++i){
		cout << ans[i];
	}
	return 0;
}
