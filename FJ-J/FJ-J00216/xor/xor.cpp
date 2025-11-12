#include<bits/stdc++.h>

using namespace std;

int n,ans=0;
long long k;
long long a[200005];
int flag1=1,flag2=0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) flag1=0,flag2=1;
		if(a[i]>1) flag2=0; 
	}	
	if(flag1==1){
		if(k==1){
			cout<<n;
			return 0;
		}else if(k==0){
			cout<<n/2;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	if(flag2==1){
		if(k==1){
			int aa=0;
			for(int i=1;i<=n;i++)
				if(a[i]==1) aa++;
			cout<<aa;
			return 0;
		}else if(k>1){
			cout<<0;
			return 0;
		}
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		sum=a[i];
		if(a[i]==k){
			ans++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			sum^=a[j];
			if(sum==k){
				ans++;
				i=j+1;
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
