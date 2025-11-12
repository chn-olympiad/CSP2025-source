#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
struct q{
	int l,r;
};
vector <q> b;
bool cmp(q x,q y){
	return (x.r-x.l)<(y.r-y.l);
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k,cnt=0,s0=0,s1=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) s0++;
		if(a[i]==1) s1++;
	}
	if(s0+s1==n){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0) cnt++;
				if(a[i]==1&&a[i+1]==1){
					cnt++;
					i++;
				}
			}
			cout<<cnt;
			return 0;
		}
		if(k==1){
			cout<<s1;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		a[i]^=a[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((a[j]^a[i-1])==k){
				b.push_back({i,j});
			}
		}
	}
	sort(b.begin(),b.end(),cmp);
	for(auto it=b.begin();it!=b.end();it++){
		bool f=0;
		for(int i=(*it).l;i<=(*it).r;i++){
			if(a[i]==-1e9){
				f=1;
				break;
			}
		}
		if(f==0){
			cnt++;
			a[(*it).l]=-1e9,a[(*it).r]=-1e9;
		}
	}
	cout<<cnt;
	return 0;
 }
