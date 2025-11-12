#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll num[1000010],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stddout);
	cin>>s;
	ll len=s.size();
	for(ll i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			num[cnt]=s[i]-'0';
		}
	}
	sort(num+1,num+cnt+1);
	for(ll i=cnt;i>=1;i--){
		cout<<num[i];
	}
	return 0;
}
