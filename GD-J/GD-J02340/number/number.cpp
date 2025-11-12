#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+10;
int num[N],cnt;
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if('0'<=s[i]&&s[i]<='9'){
			num[++cnt]=s[i]-'0';
		}
	sort(num+1,num+1+cnt);
	if(num[cnt]==0)cout<<0;
	else{
		for(int i=cnt;i>=1;i--){
			cout<<num[i];
		}
	}
	return 0;
} 
