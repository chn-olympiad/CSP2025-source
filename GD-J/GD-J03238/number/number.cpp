#include<bits/stdc++.h>
using namespace std;
string s,ans;
long long len;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	len=s.size();
	for(long long i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')ans+=s[i];
	}
	sort(ans.begin(),ans.end(),cmp);
	cout<<ans;
	return 0;
}
