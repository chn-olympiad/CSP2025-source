#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[1005],sum;
long cnt=0;
int main()
{
	long long hhh=0;
	//#Shang4Shan3Ruo6Shui4
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			cnt++;
			hhh=i;
		}
	}
	if(hhh==1){
		for(int i=2;i<=n;i++){
			sum=int(sum^a[i]);
		}
		if(sum==k)cnt++;
	}else if(hhh==n){
		for(int i=1;i<n;i++){
			sum=int(sum^a[i]);
		}
		if(sum==k)cnt++;
	}
	cout<<cnt;
	return 0;
} 
