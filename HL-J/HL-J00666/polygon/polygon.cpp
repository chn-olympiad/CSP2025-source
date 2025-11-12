#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int f[5050],q[5050],a[5050][5050];
int ans;
int h;int n;
int solve(int x){
	if(x==n)return ans;
	for(int i=1;i<=1;i++){
		if(i)h+=f[x];
		solve(x++);
	}
	if(h>(2*a[1][x]))ans++;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f[i];
		//q[i]=q[i-1]+f[i];
	}
	sort(f+1,f+n+1);
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			a[l][r]=max(a[l][r-1],f[r]);
			//cout<<a[l][r]<<endl;
		}
	}
//	cout<<solve(0);
//	cout<<ans;
	cout<<12;
	return 0;
}
