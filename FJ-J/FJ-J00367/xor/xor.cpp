#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[500005];
int ans=0;
bool pd1() {
	for(int i=1; i<=n; i++) {
		if(a[i]!=1) {
			return false;
		}
	}
	return true;
}
bool pd2() {
	for(int i=1; i<=n; i++) {
		if(a[i]>1)return false;
	}
	return true;
}

void dfs(int x,int s) {
	//cout<<x<<" "<<s<<endl;
	if(x==n+1) {
		ans=max(ans,s);
		return;
	}
	bool flag=false;
	int Xor=a[x];
	for(int i=x; i<=n; i++) {
		if(Xor==k) {
			//cout<<x<<" "<<i<<endl;
			dfs(i+1,s+1);
			flag=true;
		}
		if(i!=x) {
			Xor^=a[i];
		}
	}
	if(Xor==k) {
		//cout<<x<<" "<<i<<endl;
		dfs(n+1,s+1);
		flag=true;
	}
	if(flag==false) {
		dfs(x+1,s);
	}
}

int v[500005];
void solve1(){
	if(k==1) {
			cout<<n<<endl;
		} else if(k==0) {
			cout<<n/2<<endl;
		}
}
void solve2(){
	int l=1,r=1;
	bool flag=false;
	while(l<=n&&r<=n) {
		int p;
		if(l==1) {
			p=v[r];
		} else if(r==n) {
			p=v[n]^v[l-1];
		} else {
			p=v[n]^v[l-1]^(v[n]^v[r]);
		}
		if(p==k) {
			//cout<<l<<" "<<r<<endl;
			flag=true;
			ans++;
			l=r+1;
			r=l;
		} else{
			if(r==n){
				l++;
				r=l;
			}else{
				r++;
			}
		}
		
	}
}
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(i==1) {
			v[i]=a[i];
		} else {
			v[i]=v[i-1]^a[i];
		}
	}
	if(pd1()) {
		solve1();
	}else if(n<=10){
		dfs(1,0);
	}else{
		solve2();
	}
	cout<<ans<<endl;
	return 0;
}

