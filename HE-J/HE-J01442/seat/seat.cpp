#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,cnt,c,r,a[110],sum,sum1,w;


signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>=a[1]){
			cnt++;
		}
	}
	sum=cnt/n;
	sum1=sum*n;
	if(sum1==cnt){
		if((sum%2)==0) {
			cout<<sum<<" "<<1;
			return 0;
		}
		if((sum%2)!=0){
			cout<<sum<<" "<<n;
			return 0;
		}
	}
	if(sum1<cnt){
		w=cnt%n;
		if(((sum+1)%2)!=0) {
			cout<<sum+1<<" "<<w;
			return 0;
		}
		if(((sum+1)%2)==0){
			cout<<sum+1<<" "<<(n-w+1);
			return 0;
		}
	}
	
	
	return 0;
}
