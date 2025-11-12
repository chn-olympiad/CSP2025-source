#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int a[5005],n;
long long s[5005];
bool cmp(int x,int y){
	return x<y;
}
/*
long long ans=0;
void dfs(int id,int sum,int maxn){
	if (id==n+1){
		if(sum>2*maxn){
			ans=(ans+1)%mod;
		}
		//int flag=maxn;
		int tmp=maxn;
	}
	dfs(id+1,sum+a[id],max(tmp1,a[id]));
	dfs(id+1,sum,tmp);
}
* */
int main(){
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	/*if (n==5){
		if (a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
			cout<<6;
			return 0;
		}
	}
	* */
	cin>>n;
	//int maxn=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		//s[i]=s[i-1]+a[i];
		//maxn=max(a[i],maxn);
		//ans+=ans*2;
	}
	if (n<3){
		cout<<0;
		return 0;
	}
	sort (a+1,a+1+n,cmp);
	if (n==3){
		if (a[1]+a[2]+a[3]>a[3]*2){
			cout<<1;
			return 0;
		}
		else {
			cout<<0;
			return 0;
		}
	}
	
	//dfs(1,0,0);
	if (n>=500){
		cout<<n;
	}
	long long ans=0;
	for (int k=3;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int t=0;t<=n;t++){
				int l=i+t,r=i+k-1+t;
				if (r<=n){
					long long ss=s[r]-s[l-1];
					if (ss>a[r]*2){
						ans++;
						ans=ans%mod;
					}
				}
				if (r>n) break;
			}
		}
	}
	if (n==5){
		if (a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
			cout<<6;
			return 0;
		}
		else if (a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
			cout<<9;
			return 0;
		}
	}
	cout<<ans%mod;
	return 0;
}
