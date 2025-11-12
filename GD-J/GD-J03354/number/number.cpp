#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+10;
int stk[N],cnt=0;
bool cmp(int X,int Y){
	return X>Y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin>>s;
	int n=s.size();
	s=" "+s;
	
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			stk[++cnt]=s[i]-'0';
		}
	}
	
	sort(stk+1,stk+1+cnt,cmp);
	
	for(int i=1;i<=cnt;i++){
		cout<<stk[i];
	}
	
	return 0;
}
