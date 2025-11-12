#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,k,a[N],ta=1,dp[N],ans2;
int qj(int l,int r){
	int e=a[l];
	for(int i=l+1;i<=r;i++){
		e=e^a[i];
	}
	return e;
}
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]!=1)ta=0;
	}
	dp[n]=(a[n]==k);
	
	if(ta&&k==0){
		cout<<n/2;
	}else{
		for(int i=n-1;i>=1;i--){
			int ma=0;
			bool f=0;
			for(int j=i;j<=n;j++){
				if(qj(i,j)==k){
					for(int k=j+1;k<=n;k++){
						ma=max(ma,dp[k]);
						f=1;
					}
				}
			}
			if(f)dp[i]=ma+1;
			else dp[i]=ma;
		}
	}
	for(int i=1;i<=n;i++){
		ans2=max(ans2,dp[i]);
	}
	cout<<ans2;
	return 0;
}
