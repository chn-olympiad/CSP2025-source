#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int maxn=1000000+10;
int len,num[maxn],cnt;
string s;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>s;
	len=s.size();
	s=" "+s;
	for(int i=1;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			num[cnt]=s[i]-'0';
		}
	}
	sort(num+1,num+cnt+1,cmp);
	for(int i=1;i<=cnt;i++) cout<<num[i];
	return 0;
}