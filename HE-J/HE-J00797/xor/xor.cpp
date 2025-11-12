#include<bits/stdc++.h>
using namespace std;
int n,k;
const int maxn=5e5+10;
int a[maxn],b[maxn],c[maxn];
int check(){
	int flag=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=1)flag=false;
	}
	if(flag)return 1;
	flag=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=1&&a[i]!=0)flag=false;
	}
	if(flag)return 2;
	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	b[0]=0;
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]^a[i];
		c[i]=k^b[i];
	}
	if(check()==1){
//		int ans=0;
//		for(int i=1;i<=n;i++){
//			if(c[i]==0){
//				ans++;
//			}
//			for(int j=i+1;j<=n;j++){
//				if(b[j]==c[i])ans++;
//			}
//		}
		if(k==1)cout<<n;
		else if(k==0)cout<<n/2;
		else cout<<0;
	}else if(check()==2){
		if(k==1){
			int sum=0;
			for(int i=1;i<=n;i++){
				sum+=a[i];
			}
			cout<<sum;
		}else if(k==0){
			int sum=0;
			for(int i=1;i<=n;i++){
				sum+=a[i];
			}
			if(sum==n/2)cout<<sum-1;
			else cout<<min(sum,n-sum);
		}else{
			cout<<0;
		}
	}else{
		int ans=0;
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				ans++;
			}
			for(int j=i+1;j<=n;j++){
				if(b[j]==c[i])ans++;
			}
		}
		cout<<ans;
	}

	return 0;
}
