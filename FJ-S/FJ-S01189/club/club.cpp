#include<bits/stdc++.h>
using namespace std;
int n, t;
map<int, bool> flag;
struct New{
	int a, b, c;
}a[100010];
vector<New> aa;
pair<int, int> c[100010];
bool pd(New& n1, New& n2){
	return n1.a-n1.b<n2.a-n2.b;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(t--){
		cin>>n;
		aa.clear();
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			flag[i] = false;
		}
		sort(a+1, a+n+1, pd);
		for(int i=1;i<=n;i++){
			c[i].first = a[i].c-max(a[i].a, a[i].b);
			c[i].second = i;
//			cout<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<" ; ";
		}
//		cout<<endl;
		long long ans = 0;
		sort(c+1, c+n+1);
		for(int i=n;i>=n/2 && c[i].first>0;i--){
			ans += a[c[i].second].c;
//			cout<<c[i].second<<" ";
			flag[c[i].second] = true;
		}
//		cout<<endl;
		for(int i=1;i<=n;i++){
			if(!flag[i]){
				aa.push_back(a[i]);
			}
		}
		for(int i=0;i<int(aa.size())-n/2;i++){
			ans += aa[i].b;
		}
		for(int i=n/2;i<int(aa.size());i++){
			ans += aa[i].a;
		}
		for(int i=int(aa.size())-n/2;i<n/2;i++){
			ans += max(aa[i].a, aa[i].b);
		}
		cout<<ans<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<a[i].a<<" "<<a[i].b<<" ; ";
//		}	
//		cout<<endl;
	}
	
	return 0;
} 
