#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=510;
int n,m;
int a[N];
char c[N];
ll ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int cnt1=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		cnt1+=(c[i]-'0');
	} 
	if(cnt1<m){
		cout<<0;
		return 0;
	}
	int cnt2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!a[i]) cnt2++;
	}
	if(min(cnt1,n-cnt2)<m){
		cout<<0;
		return 0;
	}
	cout<<ans;
	return 0;
}

