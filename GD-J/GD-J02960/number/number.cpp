#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e6+5;
string s;
int ans[N],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)if(s[i]>='0'&&s[i]<='9')ans[++cnt]=s[i]-'0';
	sort(ans+1,ans+cnt+1);
	if(ans[cnt]==0){
		cout<<0;
		return 0;
	}
	for(int i=cnt;i>=1;i--)cout<<ans[i];
	return 0;
}
