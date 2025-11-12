#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],sum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			sum++;
		}
	}
	sum++;
	int df=sum/n;
	if(sum%n!=0){
		df++;
	}
	if((df)%2==0){
		cout<<df<<" "<<n-((sum-1)%n+1)+1;
	}else{
		cout<<df<<" "<<((sum-1)%n+1);
	}
	return 0;
} 
