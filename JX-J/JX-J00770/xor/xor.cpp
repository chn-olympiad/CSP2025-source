#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],q[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	bool f=1,f1=1;
	cin>>a[1];
	q[1]=a[1];
	if(a[1]!=0&&a[1]!=1)f1=0;
	
	
	for(int i=2;i<=n;i++){
		cin>>a[i];
		q[i]=int(q[i-1]^a[i]);
		
		if(a[i]!=a[i-1])f=0;
		if(a[i]!=0&&a[i]!=1)f1=0;
	}
	if(f&&k==0){
		if(a[1]!=0)cout<<n/2;
		else cout<<n;
		return 0;
	}
	else if(f1){
		if(k==1){
			int cnt=0;
			for(int i=1;i<n;i++){
				if(a[i]!=a[i+1]){
					cnt++;
					i+=2;
				}
				else if(a[i-1]==a[i]&&a[i]==a[i+1]&&a[i]==1){
					cnt++;
					i+=2;
				}
			}
			cout<<cnt;
		}
		else{
			int cnt=0;
			for(int i=1;i<n;i++){
				if(a[i]==0)cnt++;
				else if(a[i]==a[i+1]){
					cnt++;
					i+=2;
				}
			}
			if(a[n]==0)cnt++;
			cout<<cnt;
		}
		return 0;
	}
	else{
		
	}
	return 0;
}
