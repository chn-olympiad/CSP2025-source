#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	
	cin>>s;
	ll ans[s.size()+5],cnt=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			ans[cnt]=int(s[i]-'0');
			cnt++;
		}
	}
	sort(ans+1,ans+cnt);
	for(int i=cnt-1;i>=1;i--){
		cout<<ans[i];
	}
	return 0;
} 
/*
CCF CSP-J/S 2025 RP++
当前题目：J T1
赛时预估：大约100pts 保底90pts 红题 
版权所有 请勿翻录
陈彦羽
2025/11/1
惠州中学
*/ 
