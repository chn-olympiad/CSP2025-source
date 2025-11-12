#include<bits/stdc++.h>
using namespace std;
const int N=5010,p=998244353;
int n,a[N],f[N];
vector<int>s[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		for(int j=1;j<i;j++){
			for(int k:s[j]){
				if(k>a[i]) f[i]=(f[i]+1)%p;
				s[i].push_back(k+a[i]);
			}
		}
		s[i].push_back(a[i]);
	}
	cout<<f[n];
	return 0;
}