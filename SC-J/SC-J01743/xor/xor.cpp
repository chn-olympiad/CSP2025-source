#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,b[500005],a[500005];
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1){
		if(a[0]!=k){
			cout<<0;
			return 0;
		}
		else{
			cout<<1;
			return 0;
		}
	}
	if(n==2){
		if(a[0]==k&&a[1]==k){
			cout<<1 ;
			return 0;
		}
		else if(a[0]==a[1]){
			cout<<2;
			return 0;
		}
		if(a[0]==0||a[1]==0)
		{
			cout<<1;
			return 0;
		}
	}
	int sum=0;
	bool num=0;
	if(k==0){
		sort(a,a+n);
		for(int i=0;i<n;i++){
			if(a[i]==0){
				sum++;
			}
			else if(a[i]==a[i+1]){
				sum++;
				i++;
			}
		}
			cout<<sum;
	}
}