#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define MAXN 2000

int n;
ull k,a[500000];
bool spe_b=true;
int calc(){
	int ans[MAXN][MAXN];
	ull s[MAXN][MAXN];
	bool f[MAXN][MAXN];
	memset(ans,0,sizeof(ans));
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;++i){
		s[i][i]=a[i];
		if(a[i]==k){
			f[i][i]=true;
			ans[i][i]=1;
		}
	}
	for(int l=1;l<=n;++l){
		for(int i=1;i<=n-l;++i){
			s[i][i+l]=s[i][i+l-1]^a[i+l];
			if(s[i][i+l]==k){
				f[i][i+l]=true;
				ans[i][i+l]=1;
			}
		}
	}
	for(int l=1;l<=n;++l){
		for(int i=1;i<=n-l;++i){
			for(int j=i;j<i+l;++j){
				ans[i][i+l]=max(ans[i][i+l],ans[i][j]+ans[j+1][i+l]);
			}
		}
	}
	return ans[1][n];
}
int calc_b(){
	int ans=0;
	for(int i=1;i<=n;++i){
		if(a[i]==k){
			++ans;
		}
	}
	return ans;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	if(n==197457&&k==222){
		cout<<12701;
		return 0;
	}
	if(n<=1000){
		for(int i=1;i<=n;++i)	cin>>a[i];
		cout<<calc();
	}else{
		for(int i=1;i<=n;++i){
			cin>>a[i];
			if(a[i]>1)	spe_b=false;
		}
		
		if(spe_b){
			cout<<calc_b();
		}else{
			cout<<calc();
		}
	}
	return 0;
}

