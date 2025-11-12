#include <bits/stdc++.h>
using namespace std;
int T,n,a[100005],b[100005],c[100005],t1[100005],t2[100005],t3[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		int cnt1 = 0,cnt2 = 0,cnt3 = 0,sum = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d %d %d",&a[i],&b[i],&c[i]);
			if(a[i] >= b[i] && a[i] >= c[i])cnt1++,sum += a[i],t1[cnt1] = i;
			else if(b[i] >= a[i] && b[i] >= c[i])cnt2++,sum += b[i],t2[cnt2] = i;
			else if(c[i] >= a[i] && c[i] >= b[i])cnt3++,sum += c[i],t3[cnt3] = i;
		}
		vector<int>v;
		if(cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2){
			cout << sum << endl;
			continue;
		}
		if(cnt1 > n / 2){
			for(int i = 1;i <= cnt1;i++)v.push_back(min(a[t1[i]]-b[t1[i]],a[t1[i]]-c[t1[i]]));
		}
		if(cnt2 > n / 2){
			for(int i = 1;i <= cnt2;i++)v.push_back(min(b[t2[i]]-a[t2[i]],b[t2[i]]-c[t2[i]]));
		}
		if(cnt3 > n / 2){
			for(int i = 1;i <= cnt3;i++)v.push_back(min(c[t3[i]]-a[t3[i]],c[t3[i]]-b[t3[i]]));
		}
		sort(v.begin(),v.end());
		for(int i = 0;i < v.size()-n / 2;i++)sum -= v[i];
		cout << sum << endl;
	}
	return 0;
}
