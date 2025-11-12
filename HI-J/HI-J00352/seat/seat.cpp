#include<bits/stdc++.h>
using namespace std;
int a[105];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=0,ans1=0;
	for(int i=1;i<=n*m;i++){
		
		if(a[1]==100){
			cout<<1<<" "<<1;
			break;
		}else
		sort(a+1,a+1+n);
		if(a[i]%m==0){
			ans=m;
		}
		if(a[i]%n==0){
			ans1=1;
		}
		if(a[i]==a[4]){
			ans=1;
			ans1=m;
		}
		
			
		}
		cout<<ans<<" "<<ans1;
	
	
	
	return 0;
} 
