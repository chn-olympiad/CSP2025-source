#include<bits/stdc++.h>
using namespace std;
long long a[1000000]={};
long long cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		if(a[i]==k){
			cnt++;
			continue;
		}
		long long l;
		for(long long j=i+1;j<n;j++){
			long long b=a[i];
			for(l=i+1;l<=j;l++){
				b=b^a[l];
			}
			if(b==k){
				cnt++;
				i=l-1;
				break;
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
