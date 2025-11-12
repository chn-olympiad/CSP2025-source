#include<cstdio>
#include<iostream>
using namespace std;
long long a[500005],sum[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	long long cnt=0;
	bool f=true;
	scanf("%d %d",&n,&k);
	cin>>a[1];
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		sum[i]+=sum[i-1]^a[i];
	}
	if(k==0){
		f=false;
		int cn=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) cn++;
		}
		cout<<cn;
	}
	int l=1,r=1;
	while(f){
		if(sum[r]-sum[l-1]==k){
			cnt++;
			r++;
			l=r;
		}
		else{
			if(r<n) r++;
			else{
				l++; r=l;
			}
		}
		if(l==r&&l==n){
			if(sum[r]-sum[l-1]==k) cnt++;
			break;
		}
	}
	if(f)cout<<cnt+1;
	return 0;
}
