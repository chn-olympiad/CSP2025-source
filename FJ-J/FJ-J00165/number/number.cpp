#include <bits/stdc++.h>
using namespace std;
string s;
long long b = 0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	long long y = s.length();
	vector<int>ans(y);
	if(y==1){
		cout << s;
		return 0;	
	}
	if(y!=1){
			for(int i=0;i<y;i++){
				if('a'<=s[i] && s[i]<='z'){
					continue;
				}else{
					s[i] = ans[b];
					b++;
				}
			}
			sort(ans.begin(),ans.end());
			for(int i=0;i<b;i++) cout << ans[i];
	}
	return 0;
}
