#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	freopen("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	int t;
	int n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>t>>n;
	int ans=0,ans1=0,ans2=0;
	int sum=1,sum1=0,sum2=0;
	int a[3]={0};
	if(n%2==1){
		for(int i=0;i<n;i++){
			cout<<a[i]; 
		if(a[i]==1){
			ans++;
		}else if(a[i]==2){
			ans1++;
		}else{
			ans2++; 
		}
		if(ans<n/2){
			sum+=ans; 
		}else if(ans1<n/2){
			sum1+=ans1;
		}else{
			sum2+=ans2;
		}
		}
	}	
	for(int i=0;i<n;i++){
		if(sum>sum1>sum2){
			cout<<sum;
		}else if(sum1>sum2>sum){
			cout<<sum1;
		}else{
			cout<<sum2;
		}
		cout<<endl; 
	}
	return 0;
} 
