#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	long long n,m,k,ans=0;
	long long a,b,c,i;
	cin>>n>>m>>k;
	for(i=0;i<n-1;i++){
		cin>>a>>b>>c;
		ans+=c; 
	}
	printf("%lld",ans);
	return 0;
}
