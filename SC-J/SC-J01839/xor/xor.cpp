#include<bits/stdc++.h>
using namespace std;
int a[500005];
int p[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0,b=1,c=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			b=0;
		}
		if(a[i]!=1&&a[i]!=0){
			c=0;
		}
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				sum++;
			}else if(p[i-1]==0&&a[i]==a[i-1]){
				sum++;
				p[i]=1;
			}
		}
		cout<<sum;
		return 0;
	}
	if(b){
		if(k==0){
			cout<<n/2;
		}else if(k==1){
			cout<<n;
		}else{
			cout<<0;
		}
		return 0;
	}
	if(c){
		if(k==0){
			int s=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					sum++;
				}else{
					s++;
					if(s==2){
						sum++;
						s=0;
					}
				}
			}
			cout<<sum;
			return 0;
		}else if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					sum++;
				}
			}
			cout<<sum;
			return 0;
		} 
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 