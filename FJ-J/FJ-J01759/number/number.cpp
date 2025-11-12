#include<bits/stdc++.h>
typedef long long ll;
const int N=1e6+5,mod=1e9+7;
using namespace std;
int t[20];
int cnt;
string s;
char ans[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>=1;i--){
		if(!t[i]) continue;
		for(int j=cnt+1;j<=cnt+t[i];j++){
			ans[j]='0'+i;
		}	
		cnt+=t[i];
	}
	if(!cnt){
		cout<<0;
		return 0;
	}else{
		for(int i=cnt+1;i<=cnt+t[0];i++){
			ans[i]='0';
		}
		cnt+=t[0];
	}
	for(int i=1;i<=cnt;i++) cout<<ans[i];
	return 0;
}
