#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll num,ans[1000005];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll n=s.size();
	for(int i=0;i<n;i++){
		char a=s[i];
		if(a<='9'&&a>='0') {
			num++;
			ans[num]=ll(a-'0');
		}
	}
	sort(ans+1,ans+num+1,cmp);
	for(int i=1;i<=num;i++){
		cout<<ans[i];
	}
	return 0;
} 
