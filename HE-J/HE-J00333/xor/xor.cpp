#include<bits/stdc++.h>
//#define int long long;
using namespace std;
const int N=5e5+47;
int n,k;
int a[N];
int dp[N];
bool fll[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f=1,f1=1,f2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1&&a[i]!=0)f=0;
		if(a[i]==1)f1=0;
		if(a[i]==0)f2=0;
	}
	if(k==0){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)cnt++;
		}
		cout<<cnt;
	}
	else if(f==1&&f1==1){
		if(k==0){
			cout<<n;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	else if(f==1&&f2==1){
		if(k==1){
			cout<<n;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	else{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k&&fll[i]==0){
				cnt++;
				fll[i]=1;
			}
		}
		for(int l=1;l<=n;l++){
			for(int r=n;r>=l;r--){
				int ans=0;
				for(int p=l;p<r;p++){
					if(fll[p]==0&&fll[p+1]==0)ans+=a[p]|a[p+1];
					else break;
				}
				if(ans==k)cnt++;
				for(int p=l;p<=r;p++){
					fll[k]=1;
				}
			}
		}
		cout<<cnt;
	}
	return 0;
}
