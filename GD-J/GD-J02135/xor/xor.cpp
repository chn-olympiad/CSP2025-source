#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,k,a[N],q[N],ans;
struct stu{
	int l,r,len;
};
vector<stu> v;
inline bool cmp(stu x,stu y){
//	if(x.len!=y.len) return x.len<y.len;
	return x.r<y.r;
}
bool b[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(register int i=1;i<=n;++i){
		cin>>a[i];
		q[i]=(q[i-1]^a[i]);
	}
	for(register int i=1;i<=n;++i){
		for(register int j=i;j<=n;++j){
			if((q[j]^q[i-1])==k){
				v.push_back({i,j,j-i+1});
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(register int i=0;i<v.size();++i){
		int l=v[i].l,r=v[i].r;
		bool hv=0;
		for(register int j=l;j<=r;++j){
			if(b[j]){
				hv=1;
				break ;
			}
		}
		if(hv) continue ;
		ans++;
//		cout<<l<<" "<<r<<"\n";
		for(register int j=l;j<=r;++j){
			b[j]=1;
		}
	}
	cout<<ans;
	return 0;
}
