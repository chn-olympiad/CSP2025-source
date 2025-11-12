#include<bits/stdc++.h>
using namespace std;
long long N,M;
int a[205];
long long ans=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>N>>M;
	for(long long i=1;i<=N*M;i++){
		cin>>a[i];
		if(i>1&&a[i]>a[1]){
			ans++;
		}
	}
	int u=ans%(2*N);
	if(u==0)cout<<ans/N<<' '<<N;
	else if(u<N)cout<<ans/N+1<<' '<<u;
	else if(u==N)cout<<ans/N<<' '<<u;
	else if(u<2*N)cout<<ans/N+1<<' '<<N-(u-N)+1;
	else cout<<ans/N<<' '<<N-(u-N)+1;
	return 0;
}
