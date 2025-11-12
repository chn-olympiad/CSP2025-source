#include<bits/stdc++.h>
using namespace std;
string s;
int cnt=0;
char ans[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]<='9' and s[i]>='0'){
			cnt++;
			ans[cnt]=s[i];
		}
	}
	sort(ans+1,ans+1+cnt);
	for(int i=cnt;i>=1;i--){
		cout<<ans[i];
	}
	return 0;
} 
