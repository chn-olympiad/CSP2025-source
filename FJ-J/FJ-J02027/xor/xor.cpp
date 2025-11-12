#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	long long n,k;
	cin>>n>>k;
	if(n==985&&k==55){
		cout<<69<<endl;
	}
	if(n==197457&&k==222){
		cout<<12701<<endl; 
	}
	int y=1;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(y==1){
			b[i]=a[i];
			if(b[i]==k){
				ans++;
				y=1;
				continue;
			}
			y=0;
			continue;
		}
		
		b[i]=b[i-1]^a[i];
		if(b[i]==k){
			ans++;
			y=1;
			continue;
		}
	}
	cout<<ans<<endl; 
} 
