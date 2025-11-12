#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("xor.in","r",stdin);	
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0){
			f=1;
		}
	}
	if(f==0){
		if(k==1){
			cout<<n;
			return 0;
		}
		if(k==0&&n%2==0){
			cout<<n/2;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		
		}
	}
	
	return 0;
}
