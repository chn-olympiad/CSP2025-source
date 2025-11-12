#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+5;
string a;
ll t[N],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>a;
	for(int i=0,tot=a.size();i<tot;i++){
		if(a[i]<'0'||a[i]>'9') continue;
		ll now=(ll)(a[i]-'0');
		t[++cnt]=now;
	}sort(t+1,t+cnt+1);
	for(int i=cnt;i>=1;i--) cout<<t[i];
	return 0;
}
