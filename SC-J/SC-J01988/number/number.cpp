#include<bits/stdc++.h>
#define int long long
using namespace std;
int num,ans[1000005];
string s;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num++;
			ans[num]=s[i]-'0';
		}
	}
	sort(ans+1,ans+num+1,cmp);
	for(int i=1;i<=num;i++){
		cout<<ans[i];
	}
	return 0;
}