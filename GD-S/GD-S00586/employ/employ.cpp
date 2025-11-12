#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll Md=998244353;
ll n,m,c[555],ans=1,cnt,res;
string s;
bool hit=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(ll i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==1){
		for(int i=0;i<s.size();i++){
			if(s[i]=='1'){
				res=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(c[i]>res) cnt++;
		}
		for(int i=1;i<=n-1;i++){
			ans=(ans*i)%Md;
		}
		ans=(ans*cnt)%Md;
		cout<<ans;
	}else{
		for(ll i=1;i<=m;i++){
			ans=(ans*(n-i+1))%Md;
		}
		cout<<ans;
	}
	return 0;
}
