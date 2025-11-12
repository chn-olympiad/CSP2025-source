#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],b[500010],ssum,sum,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]^b[i-1];
		if(a[i]==1&&a[i-1]==1)ssum++;
		else{
			ssum+=1;
			sum+=ssum/2;
			ssum=0;
		}
		if(a[i]==0)ans++;
		if(i==n){
			ssum+=1;
			sum+=ssum/2;
			ssum=0;
		}
	}
	sort(a+1,a+1+n);
	if(a[n]<=1){
		if(k==1)cout<<n;
		else if(k==0){
			cout<<sum+ans;
		}
	}
	else{
		int i=1,ans=0;
		while(i<=n){
			int pd=0;
			for(int j=i;j<=n;j++){
				if((b[j]^b[i-1])==k){
					pd=j,ans++;
					break;
				}
			}
			if(pd==0)i++;
			else i=pd+1;
		}
		cout<<ans;
	}
	return 0;
} 
