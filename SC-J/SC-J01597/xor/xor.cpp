#include<bits/stdc++.h>
using namespace std;
int n,p=1,m,q=1,cnt=0,sum=0;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==m){
			sum++;
		}
		if(a[i]!=1){
			p=0;
		}
		if(a[i]!=1&&a[i]!=0){
			q=0;
		}
	}
	if(p==1){
		if(m==0) cout<<n/2;
		else if(m==1) cout<<n;
		else cout<<0;
		return 0;
	}
	if(q==1){
		if(m==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0) cnt++;
				if(a[i]==1&&a[i+1]==1){
					cnt++;
					i++;
				}
			}
			cout<<cnt;
		}
		else if(m==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1) cnt++;
			}
			cout<<cnt;
		}
		else cout<<0;
		return 0;
	}
	else{
		cout<<sum;
	}
	return 0;
}