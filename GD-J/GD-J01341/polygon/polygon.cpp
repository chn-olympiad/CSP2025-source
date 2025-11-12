#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],ss,g[100005];
long long mod=998244353,ssi,ssii,ssi2=1;
bool f;
void dfs(int sum,long long maxx,int s){
	maxx=max(maxx,a[s]);
	if(sum>maxx*2) {
		/*for(int i=0;i<s;i++) 
		cout<<g[i]<<' ';
		cout<<maxx<<' '<<sum<<"\n";*/
		ss++,ss%=mod;
		return ;
	}
	//if(s==4) cout<<"OPOP";
	if(s>=n) {
	//	cout<<"\n";
		return ;
	}
//	g[s]=a[s];
	dfs(sum+a[s],maxx,s+1);
	dfs(sum,maxx,s+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1) f=1;
	} 
	if(f==0) {
		ss=0;
		ssii=n;
		for(int i=0;i<n;i++){
			for(int j=0;j<=i;j++){
				ssi=ssi%mod*(ssii-j)%mod;
			}
			for(int j=0;j<=i;j++) ssi2=ssi2*(j+1)%mod;
			ssi/=ssi2;
			ss+=ssi;
			ssi=ssii,ssi2=1;
		} cout<<ss;
	}
	else {
		dfs(0,0,0);
		cout<<ss;
	}
	
	return 0;
} 
