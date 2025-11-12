#include<bits/stdc++.h>
using namespace std;
int num[5010];
int jie(int x){
	int sum=1;
	for(int i=1;i<=x;i++){
		sum*=i;
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int ans=0,mx=0;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		mx=max(mx,num[i]);
	}
	if(n==3){
		ans=1;
	}
	else if(mx==1){
		for(int i=3;i<=n;i++){
			ans+=jie(i)/(jie(i-3)*jie(3));
		} 
	}
	cout<<ans; 
	return 0;
} 
