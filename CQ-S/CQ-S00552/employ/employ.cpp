#include<bits/stdc++.h>
using namespace std;
const int N=520;
const int P=998244353;
long long n,m,c[N],ans=1,cnt,cnt2;
string s;
bool l=true;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='0') l=false,cnt++;
	}
	if(n-cnt<m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];if(!c[i]) cnt2++;
	}
	if(n-max(cnt,cnt2)<m){
		cout<<0;
		return 0;
	}
	if(l){
		for(int i=1;i<=n;i++){
			ans=(ans*i)%P;
		}
		cout<<ans;
	}
	return 0;
}
