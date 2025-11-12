#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}  int temp=a[1];
	int ans;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==temp){
			ans=i;
			break;
		}
	}
	if(ans%n==0){
		if((ans/n)%2){
			cout<<ans/n<<' '<<n;
			return 0;
		}else{
			cout<<ans/n<<' '<<1;
			return 0;
		}
	}else{
		if((ans/n+1)%2){
			cout<<ans/n+1<<' '<<ans%n;
			return 0;
		}else{
			cout<<ans/n+1<<' '<<n-ans%n+1;
			return 0;
		}
	}
	return 0;
} 
