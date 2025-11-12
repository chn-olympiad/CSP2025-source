#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int n,k,ans=0;
int a[500010];
void solveA(){
	
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			ans++;
		}
	}
	
	return ;
}
void solveB(){
	
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			ans++;
		}
	}
	
	return ;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(k==0){
		solveA();
	}else if(k==1){
		solveB();
	}else{
		int sum=0;
		for(int i=1;i<=n+1;i++){
			if(sum>k){
				sum=0;
			}else if(sum==k){
				sum=0;
				ans++;
			}
			sum+=a[i];
		}
	}
		
	
	
	cout<<ans;
	return 0;
}
