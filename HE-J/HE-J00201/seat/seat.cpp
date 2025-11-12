#include<bits/stdc++.h>
using namespace std;
int n,m;
int r,x,cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	for(int i=2;i<=n*m;i++){
		cin>>x;
		if(x>r){
			cnt++;
		}
	}
	int ans=0;
	ans=cnt/(2*n);
	if(cnt%(2*n)==0){
		cout<<cnt/n<<" "<<1;
	}else{
		cnt=cnt%(2*n);
		if(cnt<=n){
			cout<<ans*2+1<<" "<<cnt;
		}else{
			cnt-=n;
			cout<<ans*2+2<<" "<<n-cnt+1;
		}
	}
	return 0;
}
