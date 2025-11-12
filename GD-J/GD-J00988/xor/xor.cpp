#include<bits/stdc++.h>
using namespace std;

struct Xor{
	long long l,r;
};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	int a[n];
	vector<Xor>x;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	long long c=0;
	for(long long i=n-1;i>=0;i--){
		long sum=0;
		Xor now;
		now.r=i;
		for(int j=i;j>=0;j--){
			sum=sum^a[j];
			if(sum==k){
				now.l=j;
				x.push_back(now);
				c++;
				break;
			}
		}
	}
	long long ans=0,i=c-1;
	while(i>=0){
		ans++;
		long long j=x[i--].r;
		while(j>=x[i].l&&i<c)i--;
	}
	cout<<ans;
	return 0;
}
 
