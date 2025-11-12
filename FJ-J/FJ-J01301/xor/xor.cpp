#include<bits/stdc++.h>
using namespace std;
long long n,k,cnt=0;
long long s[21]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144};
long long asd(long long x,long long y){
	long long ans=0;
	int k=1;
	while(x!=0||y!=0){
		int xx=x%2,yy=y%2;
		x/=2;
		y/=2;
		if(xx!=yy){
			ans+=s[k];
		}
		k+=1;
	}
	return ans;		
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	vector<long long>a(n+1); 
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long p=a[1];
	long long i;
	for(i=2;i<=n+1;i++){
		if(p==k){
			cnt+=1;
			p=a[i];
		}else{
			p=asd(p,a[i]);
		}
		
	}
	cout<<cnt;
	return 0;
}
