#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a,id,x,y;
}dp[1005];
bool cmp(node a,node b){
	return a.a>b.a;
}
long long x=1,y=1,idd;
long long n,m,k[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>dp[i].a;
		dp[i].id=i;
	}
	sort(dp+1,dp+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(dp[i].id==1){
			idd=i;
		}
	}
	long long k=(idd%n);
	if(idd%n==0){
		k=n;
	}
	if(k%2==0){
		if((idd+n-1)/n%2==0){
			cout<<(idd+n-1)/n<<" "<<(n-k+1)<<endl;
		}else{
			cout<<(idd+n-1)/n<<" "<<k<<endl;
		}		
	}else{
		if((idd+n-1)/n%2==0){
			cout<<(idd+n-1)/n<<" "<<(n-k+1)<<endl;
		}else{
			cout<<(idd+n-1)/n<<" "<<k<<endl;
		}
	}
	
}
