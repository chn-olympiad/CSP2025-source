#include<bits/stdc++.h>
using namespace std;
int a[105],ans=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	if(n==1&&m==1){
		cout<<n<<" "<<m;
		return 0;
	}
	int k=a[1];
	sort(a,a+sum);
	for(int i=1;i<=n*m;i++){
		if(k==a[i]){
			k=i;
		}
	}
	if(sum%2==1){
		int t=(sum+1)/2;
		if(k<t) ans=t+(t-k);
		else ans=t-(k-t);
	}
	else{
		int t=sum/2;
		if(k<t) ans=t+(t-k)+1;
		else ans=t-(k-t)-1;
	}
	if(ans==0) ans=10;
	cout<<n<<" "<<ans;
	return 0; 
} 
