#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
bool cmp(const char &x,const char &y){
	return x>y;
}
int main(void){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	str x,ans="";
	cin>>x;
	sort(x.begin(),x.end(),cmp);
	for(ll i=0;i<ll(x.size());i++){
		if(x[i]>='0'&&x[i]<='9'){
			ans+=x[i];
		}
	}
	cout<<ans;
	return 0;
}
