#include<bits/stdc++.h>
using namespace std;
const int N=1<<20;
int n,k,a[N],b[N],s[N],lst[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<(1<<20);i++) b[i]=-2;
	for(int i=1;i<=n;i++){
		int ned=s[i]^k;
		lst[i]=b[ned]+1;
		b[s[i]]=i;
	}
	int now=0;
	for(int i=1;i<=n;i++){
		if(lst[i]==-1) continue;
		if(lst[i]>now){
			now=i;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}