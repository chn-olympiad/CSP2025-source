#include<bits/stdc++.h>
using namespace std;
struct per{
	int a1,a2,a3;
};

per arr[1000009];
int t,n;
int dp(int l,int w1,int w2,int w3){
	int ans=0;
	if(w1>n/2||w2>n/2||w3>n/3||l<0) return 0;
	ans=max(dp(l-1,w1+1,w2,w3)+arr[l].a1,ans);
	ans=max(dp(l-1,w1,w2+1,w3)+arr[l].a2,ans);
	ans=max(dp(l-1,w1,w2,w3+1)+arr[l].a3,ans);
	ans=max(dp(l-1,w1,w2,w3),ans);
	return ans;
}
int main(){	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>> t;
	for(int j=0;j<t;j++){
		
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>arr[i].a1 >>arr[i].a2 >>arr[i].a3 ;
		}
	cout<<dp(n-1,0,0,0)<<endl;
		
		
		
		
	} 
	return 0;
} 
