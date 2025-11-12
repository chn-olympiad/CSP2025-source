#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e2+5,mod=998244353;
string s;
int dif[N],pa[N];
ll A(int x,int y){
	if(x==y){
		ll res=1;
		for(int i=1;i<=x;++i) (res*=i)%=mod;
		return res;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m; cin>>n>>m>>s;
	int pbA=1,imp=0;
	for(int i=1;i<=n;++i){
		dif[i]=s[i-1];
		cin>>pa[i];
		if(dif[i]==0) pbA=0;
		if(pa[i]==0) imp=1; 
	}
	if(m==n){
		if(imp==0 and pbA){
			cout<<A(n,n);
		}
		else cout<<0;
		return 0;
	}
//	if(m==1){
//		
//	}
	if(pbA){
		cout<<A(n,n);
		return 0;
	}
	
	
	cout<<0;
	return 0;
} 