#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],sum[500005],k;
bool flag=1;
struct ty{
	int st,ed;
};vector<ty>v;

bool cmp(ty a,ty b){
	if(a.ed==b.ed)return a.st<b.st;
	return a.ed<b.ed;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=(a[i]^sum[i-1]);
		if(a[i]!=1){
			flag=0;
		}
	}
	if(n==2&&flag&&k==0)cout<<n/2;
	else if(n==1&&flag&&k==0)cout<<0;
	else if(!flag){
		for(int len=1;len<=n;len++){
			for(int s=1;s<=n-len+1;s++){
				int e=s+len-1;
				if((sum[e]^sum[s-1])==k){
					v.push_back({s,e});
				}
			}
		}
		sort(v.begin(),v.end(),cmp);
		ty b=v[0];
		int ans=1;
		for(int i=1;i<v.size();i++){
			if(v[i].st>b.ed){
				ans++;b = v[i];
			}
			else continue;
		}cout<<ans;
	}
	return 0;
} 
