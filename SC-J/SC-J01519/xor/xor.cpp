#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
unsigned long long a[MAXN],n,k;
bool cheeky(int l,int r){
	int f=a[l];
	for(int i=l+1;i<=r;i++){
		f=f xor a[i];
	}
	if(f==k) return 1;
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];                                                                                              
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(cheeky(i,j))ans++;
		}
	}        
	cout<<ans;
	return 0;
}
//不知道算不算暴力的唐人代码
//求50 