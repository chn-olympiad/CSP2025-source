/*xg333 CSP-J must win!!!
T1代码*/
#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define endl '\n'
int a[20];	
void solve(){
	string s;
	cin>>s;
	int n=s.size();
	bool flag=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
			if(s[i]>'0') flag=1;
		}
	}
	if(flag==0) cout<<0;
	else{
		for(int cnt=9;cnt>=0;cnt--){
			for(int i=1;i<=a[cnt];i++){
				cout<<cnt;
			}
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
/*
xg333：我的思路就是把所有字符串的数提出来，放在桶里，然后从9到0依次输出，如果只有0，就直接输出0
*/