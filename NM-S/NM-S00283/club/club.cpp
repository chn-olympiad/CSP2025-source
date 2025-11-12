#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		vi f(n),s(n),cnt(3),less1,less2,less3;
		for (int i = 0;i<n;i++) {
			int a,b,c;
			cin>>a>>b>>c;
			f[i] = max(max(a,b),max(b,c));
			if (f[i]==a)s[i] = max(b,c),less1.push_back(f[i]-s[i]),cnt[0]++;
			else if (f[i]==b)s[i] = max(a,c),less2.push_back(f[i]-s[i]),cnt[1]++;
			else s[i] = max(b,a),less3.push_back(f[i]-s[i]),cnt[2]++;
		}
		long long ans = 0;
		for (int i = 0;i<n;i++)ans+=f[i];
		if (cnt[0]>n/2) {
			sort(less1.begin(),less1.end());
			for (int i = 0;i<cnt[0]-n/2;i++)ans-=less1[i];
			cout<<ans<<endl;
			//return 0;
		}else if (cnt[1]>n/2) {
			sort(less2.begin(),less2.end());
			for (int i = 0;i<cnt[1]-n/2;i++)ans-=less2[i];
			cout<<ans<<endl;
			//return 0;
		}else if (cnt[2]>n/2) {
			sort(less3.begin(),less3.end());
			for (int i = 0;i<cnt[2]-n/2;i++)ans-=less3[i];
			cout<<ans<<endl;
			//return 0;
		}else {
			cout<<ans<<endl;
			//return 0;
		}
	}
}
