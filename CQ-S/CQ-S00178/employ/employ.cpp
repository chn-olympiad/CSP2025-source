#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	bool flag=1;
	for(int i=0;i<s.length();i++){
		if(s[i]==0){
			flag=0;
			break;
		}
	}
	if(flag==1){
		int cnt=n;
		int cnt2=1;
		int ans=1;
		int ans2=1;
		for(int i=1;i<=n;i++){
			int t;
			cin>>t;
			if(t==0){
				cnt--;
				cnt2++;
			}
		}
		if(n-cnt2<m){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=cnt;i++){
			ans*=i;
		}
		for(int i=cnt2;i<=cnt+1;i++){
			ans2*=i;
		}
		cout<<ans*ans2;
	}
	else cout<<0;
	return 0;
}

