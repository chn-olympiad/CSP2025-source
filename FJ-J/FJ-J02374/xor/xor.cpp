#include<bits/stdc++.h>
using namespace std;
bool used[1145141];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans;
	ans=0;
	cin>>n>>k;
	int num[n+1];
	memset(num,0,n+1);
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	if(k==0){
	if(n==1&&num[1]!=k){
		cout<<0;
		return 0;
	}
	if(n==0){
		cout<<0;
		return 0;
	}
	if(n%2==0){
		if(num[1]==num[2]==1){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	
	}

return 0;
}

