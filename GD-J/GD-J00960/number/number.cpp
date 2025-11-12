#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+7;
string s;
ll len,ans[N],idx;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			idx++;
			ans[idx]=s[i]-'0';
		}
	}
	sort(ans+1,ans+idx+1);
	for(int i=idx;i>=1;i--)printf("%lld",ans[i]);
	return 0;
} 
