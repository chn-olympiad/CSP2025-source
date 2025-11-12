#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,y;
int main(){
	freopen("seat.in","r",stdin);	
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>a[i];
	}
	int ans,num=a[1],sum;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			sum=i;
			break;
		}
	}
	ans=n*m-sum+1;
	x=(ans-1)/n+1;
	if(x%2==0){
		y=n-(ans-1)%n;
	}
	else{
		y=(ans-1)%n+1;
	}
	cout<<x<<" "<<y;
	return 0;
}
