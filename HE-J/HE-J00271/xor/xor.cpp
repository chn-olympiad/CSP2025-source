#include<bits/stdc++.h>
using namespace std;
int n,k,m[500005],ans,a=0;
void fun(int b){
	int i=b;
	int j=b;
	for(;i<=n;i++){
		for(;j<=n;j++){
			a=a^m[i];
			if(a=k){
				ans+1;
				break;
			}
		}
	}
	if(i>j){
		fun(i);
	}
	else if(i<=j){
		fun(j);
		if(i==n&&j==n){
			return;
		}
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>m[i];
	}
	fun(1);
	cout<<ans;
	return 0;
} 
