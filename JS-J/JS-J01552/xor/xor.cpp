#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long k;
	int n,c=1,b=1,s;
	cin>>n>>k;
	int a[500005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			s++;
		}
		if(a[i]!=1){
			c=0;
		}
		if(a[i]>1){
			b=0;
		}
	}
	if(c && k==0){
		cout<<n/2;
	}
	else if(b && k<=1){
		if(k==1){
			cout<<s;
		}
		if(k==0){
			int cnt=0;
			for(int i=1;i<n;i++){
				if(a[i]==1 && a[i+1]==1){
					cnt++;
				}
				else if(a[i]==0)
					cnt++;
			}
			if(a[n]==0)
				cnt++;
			cout<<cnt;
		}
	}
}
