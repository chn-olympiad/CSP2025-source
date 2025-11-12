#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			ans=n*m-i+1;
			break;
		}
	}
	//cout<<ans<<" ";
	cout<<(ans+n-1)/n<<" ";
	if(((ans+n-1)/n)%2==0){
		cout<<n-((ans-1)%n);
	}
	else{
		cout<<(ans-1)%n+1;
	}
	return 0;
}
