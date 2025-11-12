#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+20;
string s;
int cnt;
int ans[N];

bool cmp(int x,int y){
	return x>y;
}

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int  i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans[++cnt]=s[i]-'0';
		}		
	}
	sort(ans+1,ans+cnt+1,cmp);
	for(int i=1;i<=cnt;i++) cout<<ans[i];
	return 0;
}

