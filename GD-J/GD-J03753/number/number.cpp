#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6;
ll a[N];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll n=0;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++n]=s[i]-'0';
//			cout<<a[n]<<" ";
		}
	}
	sort(a+1,a+1+n,cmp);
	for(ll i=1;i<=n;i++)printf("%lld",a[i]);
	
	return 0;
	fclose(stdin);
	fclose(stdout);
}
/*
5
5

290es1q0
92100

0u050hz08t2ibm70y4exp04u6m44838cont753674e569zh6hpkxr9tyd0l1odacalb5u0a835e7631x9581dy8pnui496e7t0bx
99998888887777766666655555544444433332111000000000


*/
