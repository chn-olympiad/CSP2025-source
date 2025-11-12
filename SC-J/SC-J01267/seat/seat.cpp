#include<bits/stdc++.h>
using namespace std;

int a[100+10];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	int k;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	
	sort(a+1,a+n*m+1);
	
	int sum=0;
	for(int i=n*m;i>=1;i--){
		sum++;
		if(a[i]==k){
			break;
		}
	}
	
	if(sum<n){
		cout<<1<<" "<<sum;
	}else if(sum%n==0){
		if((sum/n)%2==1){
			cout<<1<<" "<<n;
		}else{
			cout<<sum/n<<" "<<1;
		}
	}else{
		int x,y;
		x=sum/n+1;
		if(x%2==0){
			y=sum%n+1;
		}else{
			y=sum%n;
		}
		cout<<x<<" "<<y;
	}
	
	return 0;
}
