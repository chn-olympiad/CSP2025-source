#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,a[500005],num,b[500005];
int yh(long long a,long long b){
	ans=0;
	if(a>b){
		int t=a;
		a=b,b=t;
	}
	int p=1;
	while(b!=0){	
		if(a%2!=b%2) ans+=p;
		a/=2,b/=2,p*=2;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n-l+1;i++){
			int j=i+l-1;
			long long flag=1,check=0;
			for(int k=i;k<=j;k++){
				if(b[k]==1){
					flag=0;
					break;
				}
				check=yh(check,a[k]);
			}
			if(flag&&check==k){
				for(int k=i;k<=j;k++) b[k]=1;
				num++;
			}
		}
	}
	cout<<num;
return 0;
}
