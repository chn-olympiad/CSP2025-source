#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
string s;
ll ans[N],j;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			j++;
			ans[j]=s[i]-'0';
		}
	}
	sort(ans+1,ans+j+1,cmp);
	for(ll i=1;i<=j;i++) cout<<ans[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
