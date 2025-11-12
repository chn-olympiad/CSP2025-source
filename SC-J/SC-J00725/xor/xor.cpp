#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	vector<long long> aa(n+1);
	bool a=1,b=1;
	for(long long i=0;i<n;i++){
		cin>>aa[i];
		if(!aa[i])a=0;
		if(aa[i]!=1&&aa[i]!=0)b=0;
	}
	if(a){//10
		long long q=k*2-1;
		n/=q;
		cout<<n;
		return 0;
	}
	else if(b){//20
		vector<long long> c(n+1);
		long long ans=0;
		long long kk=0;
		c[0]=aa[0];
		for(long long i=1;i<n;i++){
			if(aa[i]==0){
				if(!c[i-1]){
					kk=0;
				}
				c[i]=1;
			}
			else c[i]^=c[i-1];
			kk+=c[i];
			if(kk==k)ans++;
		} 
		cout<<ans;
		
		return 0;
	}
	else {
		vector<long long> c=aa;
		long long kk=0;
		for(long long i=1;i<n;i++){
			c[i]^=c[i-1];
			kk+=c[i];
		}
		cout<<kk/k;
	}
	//0比全1时，使后权值序列中1变成0,0变成1 ????
	//若0前为0，则其后连续的0均为0.反之全为1 
	//所以若使值最大，因让0前为1 
	//0连续时，要么全0，要么全1 
	return 0;
}
/*
101->0
01->1
1^0=1;
0^1=1
1^1=0;
0^0=0;
10^1=3?
10^10=0;
11^1=2?
11^0=3?
11^10=1?
^->不同为1，相同为0?
 
*/
