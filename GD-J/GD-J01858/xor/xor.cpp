#include <bits/stdc++.h>
using namespace std;
const int N   = 5e5+10 , P=2500000;
long long  a[N];
int n ,k;
struct M{
	int l, r;
	bool operator< (const M a)const {
		return r<a.r;
	}
};
vector<M> v;
int las;
int ans;
int f[P];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w" , stdout);
	cin>>n>>k;
	for(int i =1 ;i<=n;i++){
		cin>>a[i];
		a[i] = a[i] ^a[i-1];
		
		
	}
	int cur;
	
	for(int i =1 ;i<=n;i++){
			cur = k^a[i];
			if(f[cur]){
			
				
				v.push_back({f[cur]+1,i});
				
				
			}
			else {
				if(cur==0){
					v.push_back({f[cur]+1,i});
					
					
				}
			
			}
			f[a[i]]=i;
		
	}
	sort(v.begin() , v.end());
	for(int i =0;i<v.size();i++){
		if(v[i].l>las){
	
			
			ans++;
			las = v[i].r;
		}
	}
	cout<<ans<<'\n';
	return 0;
	
}
