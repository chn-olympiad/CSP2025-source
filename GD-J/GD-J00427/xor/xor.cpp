#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,k,a[500010];
int main(){
	//T3
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	
	if(k==0){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)sum++;
		}
		cout<<sum;
		return 0;
	}
	if(k==1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)sum++;
		}
		cout<<sum;
		return 0;
	}
	return 0;
} 
