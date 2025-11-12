#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+9;
long long n,a[maxn],b[maxn],c[maxn],k1,k2,k3,ans;
long long _abs(long long x){
	if(x<0) return -x;
	return x;
}
void solve(){
	ans = 0;
	k1 = k2 = k3 = 0;
	cin>>n;
	for(int i = 1;i<=n;i++){
		long long x,y,z,mx,nx;
		cin>>x>>y>>z;
		mx = max(x,max(y,z));
		ans+=mx;
		if(mx == x){
			k1++;
			nx = max(y,z);
			a[k1] =  _abs(x-nx);
		}else if(mx == y){
			k2++;
			nx = max(x,z);
			b[k2] = _abs(y-nx);
		}else{
			k3++;
			nx = max(y,x);
			c[k3] = _abs(z-nx);
		}
	}
	sort(a+1,a+k1+1);
	sort(b+1,b+k2+1);
	sort(c+1,c+k3+1);
	long long mxk = max(k1,max(k2,k3)),s;
	if(mxk == k1) s = 1;
	else if(mxk == k2) s = 2;
	else s = 3;
	//cout<<s<<" ";
	if(mxk<=n/2){
		cout<<ans;
	}else{
		long long j = 1;
		for(int i = n/2+1;i<=mxk;i++){
			if(s == 1) ans-=a[j];
			else if(s == 2) ans-=b[j];
			else ans-=c[j];
			j++;
		}
		if(mxk == n && n&1){
			if(s == 1) ans-=a[j];
			else if(s == 2) ans-=b[j];
			else ans-=c[j];
		}
		cout<<ans;
	}
	cout<<endl;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
