#include<bits/stdc++.h>
using namespace std;
long long a[500000]={},b[500000]={},c[500000]={};
long long n,m=0,k,ans=0,ans1=0;
int zxj(long long x){
	long long an=a[x];
	for(long long i=x-1;i>=0;i--){
		if(b[i]==-1){
			break;
		}
		an=an^b[i];
		if(an==k){
			ans1++;b[x]=-1;m--;break;
		}
	}
}
int cyc(long long x){
	long long an=a[x];
	for(long long i=x+1;i<n;i++){
		if(b[i]==-1){
			break;
		}
		an=an^b[i];
		if(an==k){
			ans1++;b[x]=-1;break;
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int aa=0,bb=0;
	cin>>n>>k;
	for(long long i=0;i<n;i++){
		cin>>a[i];b[i]=a[i];
		if(b[i]==k){
			ans1++;b[i]=-1;
		}
		if(a[i]>1){
			aa=1;bb=1;
		}
		if(a[i]!=1)aa=1;
	}
	if(aa==0){
		if(k==0){
			cout<<n/2;
		}
		else{
			cout<<n;
		}
		return 0;
	}
	if(bb==0){
		if(k==0){
			for(long long i=0;i<n;i++){
				if(a[i]==0){
					ans++;
				}
				else{
					if(a[i+1]==1){
						ans++;i++;
					}
				}
			}
		}
		else{
			for(long long i=0;i<n;i++){
				if(a[i]==1){
					ans++;
				}
			}
		}
		cout<<ans;return 0;
	}
	for(long long i=0;i<n;i++){
		if(b[i]*2-1>=k){
			c[m]=i;m++;zxj(i);
		}
	}sort(c,c+m);
	for(long long i=m-1;i>=0;i--){
		cyc(c[i]);
	}
	cout<<ans1;
	return 0;
}

