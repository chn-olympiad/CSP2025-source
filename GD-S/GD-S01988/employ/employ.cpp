#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
const int mod=998244353;
char c[600];
int a[600],b[600];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int f=0,c1=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]=='1'){
			b[i]=1;
			c1++;
		}else{
			f=1;
			b[i]=0;
		}
	}
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(f==0){
		int sum=1;
		for(int i=1;i<=n;i++){
			sum=i*sum;
		}
		ans=sum%mod;
		cout<<ans;
		return 0;
	}else if(m==1){
		if(c1>0){
			int sum=1;
			for(int i=1;i<=n;i++){
				sum=i*sum;
			}
			ans=sum%mod;
			cout<<ans;
			return 0;
		}else{
			cout<<0;
			return 0;
		} 
	}else if(m==n){
		cout<<1;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
