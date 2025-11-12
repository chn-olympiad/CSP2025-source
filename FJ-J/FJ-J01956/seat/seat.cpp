#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n*m;i++){	
		if(a[i]>a[i+1]){
			swap(a[i],a[i+1]);
		}else{
			int js=i+1;
			ans=max(js,ans);
			a[i+1]=a[i];
		}
			 
	} 
	int sum=ans;
	
	if(sum<=n){
		cout<<"1"<<" "<<sum;
	}else if(sum>n){
		int num=sum/n;
		if(num%2==0){
		
		
		cout<<num+1<<" "<<sum-num*n;
	}else{
		 cout<<num+1<<" "<<n-sum-num*n+1;
	     }
	}	
	

	return 0;
} 
