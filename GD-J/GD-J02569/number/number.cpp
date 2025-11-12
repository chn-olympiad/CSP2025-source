#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+5;
string s;
int ans[N],cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	int ls=s.size();
	for(int i=0;i<ls;i++)
		if('0'<=s[i]&&s[i]<='9')
			ans[++cnt]=s[i]-'0';
	sort(ans+1,ans+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
		cout<<ans[i];
	return 0;
} 
