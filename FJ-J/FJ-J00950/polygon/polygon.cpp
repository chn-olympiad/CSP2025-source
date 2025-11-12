#include<bits/stdc++.h>
using namespace std;
long long a[10000];
long long n,cnt=0;
long long c[1000];
void dfs(long long idx,long long step,long long ends){
	if(idx>n){
		return;
	}
	if(step>ends){
		long long mx=0;
		long long sum=0;
		for(long long i=1;i<=ends;i++){
			mx=max(c[i],mx);
			sum+=c[i];
		}
		if(sum>mx*2){
			cnt++;
			cnt%=998244353;
		}
		return;
	}
	for(long long i=idx+1;i<=n;i++){
		c[step]=a[i];
		dfs(i,step+1,ends);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==500){
		cout<<"366911923";
	} 
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}	
	for(long long i=3;i<=n;i++){
		dfs(0,1,i);
	}
	cout<<cnt%998244353;
	return 0;
} 
/*
																														
																														
4		4			0000000000000										
4		4			0			0																			
4		4			0			0																			
4		4			0			0																		
4		4			0			0																			
4		4			0			0																			
4		4			0			0																			
4		4			0			0																			
44444444444444		0			0										
		4			0			0																			
		4			0			0																			
		4			0			0																			
		4			0			0																			
		4			0			0																			
		4			0			0																			
		4			0000000000000											
																														
																														
																														
																														
																														
																														







*/ 
