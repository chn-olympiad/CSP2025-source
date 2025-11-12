#include<bits/stdc++.h>
using namespace std;
int a[1000005],t=0;
string s;
bool cmp(int x,int y){return x>y;}
signed main(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9') a[++t]=s[i]-'0';
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++) cout<<a[i];
	return 0;
}
