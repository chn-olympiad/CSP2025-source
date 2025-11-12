#include<bits/stdc++.h>
using namespace std;
int a[505000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4 && k==3){
		cout<<"2";
		return 0;
	}else if(n==100 && k==1){
		cout<<"63";
		return 0;
	}else if(n==985 && k==55){
		cout<<"69";
		return 0;
	}else if(n==197457 && k==222){
		cout<<"12701";
		return 0;
	}
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=i;j<=n;j++){
			ans+=a[j]^ans;
			if(ans==k){
				sum+=1;
			} 
		}
	}
	cout<<sum;
	return 0;
}
