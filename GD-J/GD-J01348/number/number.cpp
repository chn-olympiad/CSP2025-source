#include<bits/stdc++.h>
using namespace std;
const int N=3e6+10;
int ans[N],len;
string s;
bool cmp(int x,int y){
	return x>y;
}
void solve(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			ans[i]=s[i]-'0';
			len++;
		}
	}
	sort(ans,ans+s.size(),cmp);
	for(int i=0;i<len;i++){
		cout<<ans[i];
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
}
