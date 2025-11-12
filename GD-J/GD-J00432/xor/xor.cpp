#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[1000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=0;
	if(m==0){
		for(int i=0;i<n;i++){
			if(a[i]==0) ans++;
			else if(a[i]==a[i+1]){
				i++;
				ans++;
			} 
		}
	}
	else if(m==1){
		for(int i=0;i<n;i++){
			if(a[i]==1) ans++;
		}
	}
	cout<<ans;
	return 0;
} 
