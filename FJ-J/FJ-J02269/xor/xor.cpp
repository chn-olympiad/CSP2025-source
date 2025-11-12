#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500009],b[500009];
int n,k;
void solve1(){
	int ans=0,sum=1e9,f=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k)ans++,b[i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=i;k<=j;k++){
				if(b[k]==0){
					f=1;
					break;
				}
				sum=(sum|a[k]);
			}
			cout<<sum<<endl;
			if(sum==k)ans++,i++,j=n+1;
			sum=1e9;
		}
	}
	cout<<ans;
	return;
}
void solve2(){
	int ans=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
		}
		for(int i=2;i<=n;){
			if(a[i]==a[i-1]&&a[i]!=0)ans++,i+=2;
			else i++;
		}
		cout<<ans;
	}else{
		int ans1=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
		for(int i=2;i<=n;){
			if(a[i]!=a[i-1])ans1++,i+=2;
			else i++;
		}
		cout<<max(ans,ans1);
	}
	return;
}
void solve3(){
	cout<<n/2;
	return;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int q=0,d=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)q++;
		else if(a[i]==1)d++;
	} 
	if(d==n){
		solve3;
	}else if(q+d==n){
		solve2();
	}else{
		solve1();
	}
	return 0;
} 
