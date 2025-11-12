#include<bits/stdc++.h>//y
using namespace std;
#define ll long long
#define vv vector

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q;
	cin>>n>>q;
	vv<string>s1(n+1),s2(n+1),t1(q+1),t2(q+1);
	for(int i=0;i<n;i++)cin>>s1[i]>>s2[i];
	for(int i=0;i<q;i++)cin>>t1[i]>>t2[i];
	for(int j=0;j<q;j++){
		int ans=0;
		for(int i=0;i<q;i++){
			if(s1[i]==t1[j]&&s2[i]==t2[j])ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
