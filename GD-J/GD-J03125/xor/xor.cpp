#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int cnt=0;
int ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<n/2;
	}
	else{
		int sum=0;
		for(int i=1;i<=n;i++){
			int c=sum^a[i];
			sum=c;
			if(c==k){
				sum=0;
				ans++;
			}
		}
	cout<<ans;
	}
	return 0;
}

