#include<bits/stdc++.h>

using namespace std;
long long n,k,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	vector<long long> a(n+5,0);
	vector<long long> s(n+5,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=(s[i-1]^a[i]);
	}
	int lim=1;
	for(int r=1;r<=n;r++){
		for(int l=r;l>=lim;l--){
			if(k==(s[r]^s[l-1])){
				ans++;
				lim=r+1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
