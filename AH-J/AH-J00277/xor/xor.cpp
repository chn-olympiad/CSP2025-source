#include<bits/stdc++.h>
using namespace std;
long long a[500002],b[500002],yh[500002];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a0=0,a1=0,s=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) a1++;
		if(a[i]==0) a0++;
	}
	if(k==0&&a1==n){	
		cout<<n/2;
		return 0;
	}
	if(k<=1&&a0+a1==n){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i-1]==a[i]&&b[i-1]==0){
					b[i-1]=b[i]=1;
					s++;
				}
			}
		}
		if(k==1)
			cout<<a1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		yh[i]=yh[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((yh[j]^yh[i-1])==k){
				s++;
				i=j;
				break;
			}
		}
	}
	cout<<s;
	return 0;
}
