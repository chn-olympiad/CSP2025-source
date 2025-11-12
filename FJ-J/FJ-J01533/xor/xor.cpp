#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	long long n,zhi;
	cin>>n>>zhi;
	long long xulie[n];
	bool shiyong[n]={false};
	long long sum=0,i;
	for(i=0;i<n;i++) cin>>xulie[i];
	for(long long len=1;len<=n;len++){
		for(long long start=0;start<=n-len;start++){
			bool d=false;
			long long quanzhi=0;
			for(i=start;i<start+len;i++){
				quanzhi^=xulie[i];
				if(shiyong[i]) d=true;
			}
			if(d||quanzhi!=zhi) continue;
			sum++;
			for(i=start;i<start+len;i++) shiyong[i]=true;
		}
	}
	cout<<sum;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}