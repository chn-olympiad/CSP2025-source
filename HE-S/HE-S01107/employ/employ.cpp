#include<bits/stdc++.h>
using namespace std;

long long n,k,num,ans;
string s;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>num;
		ans=max(ans,num);
	}cout<<ans;
	return 0;
}
