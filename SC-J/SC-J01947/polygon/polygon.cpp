#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int maxn=5010;
const int mod=998244353;
struct node{
	int w,maxid,len;
};
int n,a[maxn],ans;
vector<node> v;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int t=v.size();
		for(int j=0;j<t;j++){
			v.push_back((node){a[i]+v[j].w,i,v[j].len+1});
		}
		v.push_back((node){a[i],i,1});
	}
	for(int i=0;i<v.size();i++){
		if(v[i].len==1){
			continue;
		}
		for(int j=v[i].maxid+1;j<=n;j++){
			if(v[i].w>a[j]){
				ans++;
				ans%=mod;
			}
		}
	}
	cout <<ans;
	return 0;
}