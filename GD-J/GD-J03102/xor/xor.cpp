#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,k,sum=0,sumi=0;
	bool flag=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)sum++;
		if(a[i]==0){
			flag=0;
			sumi++;
		}
	} 
	if(k==0){
		if(flag){
			cout<<n/2;
		}else{
			cout<<max(sum/2,sumi);
		}
	}else if(k==1){
		cout<<sum;
	}
	return 0;
}
