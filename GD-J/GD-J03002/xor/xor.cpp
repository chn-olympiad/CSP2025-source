#include <bits/stdc++.h>
//T3
using namespace std ;
const int N=5e5+300,M=2097152+500 ;
int n,k,f[N],a[N],P[N],ans,L[M*2];
int main () {
	freopen ("xor.in","r",stdin) ;
	freopen ("xor.out","w",stdout) ;
//	freopen ("hh","w",stdout) ;
	cin>>n>>k ;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		P[i]=(P[i-1]^a[i]) ;
		f[i]=-1;
	}
	memset(L,-1,sizeof L);
	
	L[0]=0;f[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=max(f[i],f[i-1]);
		if(L[(P[i]^k)]==-1) {
			f[i]=max(0,f[i]);
		}
		else{
			f[i]=max(f[i],f[L[P[i]^k]]+1);
		}    
		if(f[i]>=f[L[P[i]]]) L[P[i]]=i;                  
		ans=max(ans,f[i]) ;
	} 
	cout<<ans;
	return 0 ;
}
