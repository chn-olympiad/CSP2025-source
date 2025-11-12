#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
void check(int ans1,int ans2){
	if(n==m){
		if(ans2==0){
			if(ans1%2==0) cout<<ans1<<' '<<1;
			else cout<<ans1<<' '<<n;
		}else if(ans2==1){
			if(ans1%2==1) cout<<ans1+1<<' '<<n;
			else cout<<ans1+1<<' '<<1;
		}else{
			if(ans1%2==0) cout<<ans1+1<<' '<<n-ans2;
			else cout<<ans1+1<<' '<<ans2+1;
		}
	}else{
		if(ans1==0) cout<<1<<' '<<ans2;
		else if(ans1==1&&ans2==0) cout<<n<<' '<<1;
		else{
			if(ans2==0){
				if(ans1%2==0) cout<<ans1<<' '<<1;
				else cout<<ans1<<' '<<n;
			}else if(ans2==1){
				if(ans1%2==1) cout<<ans1+1<<' '<<n;
				else cout<<ans1+1<<' '<<1;
			}else{
				if(ans1%2==0) cout<<ans1+1<<' '<<n-ans2;
				else cout<<ans1+1<<' '<<ans2+1;
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int ph=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(ph==a[i]){
			ph=i;
			break;
		}
	}
	int ans1=ph/n;
	int ans2=ph%n;
	//cout<<ans1<<' '<<ans2<<endl;
	check(ans1,ans2);
	return 0;
}
