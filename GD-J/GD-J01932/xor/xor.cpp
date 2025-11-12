#include<bits/stdc++.h>
using namespace std;
long long n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long a[n+5],sum,ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			continue;
		}
		for(int m=1;m<n;m++){
			sum=a[i];
			for(int f=1;f<=m;f++){
				if(i+f>n) break;
				sum=sum^a[i+f];
			}	
			if(sum==k){
				i=i+m;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
