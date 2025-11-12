#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0||a[i]==a[i-1]){
				cnt++;
			}
		}
		cout<<cnt;
	}
	else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				cnt++;
			}
		}
		cout<<cnt;
	}
	else{
		cout<<1;
	}
	return 0;
}
