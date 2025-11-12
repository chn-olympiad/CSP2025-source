#include<bits/stdc++.h>
using namespace std;
const int mod=1e18;
long long s[500010];
int yh(long long x,long long y){
	bool a[50],b[50],ans[50];
	int t1=0;
	while(x){
		a[t1]=x%2;
		x/=2;
		t1++;
	}
	int t2=0;
	while(y){
		b[t2]=y%2;
		y/=2;
		t2++;
	}
	if(t1 > t2){
		for(int i=t1;i>=0;i--){
			if(a[i]!=b[i]){
				ans[i]=1;
			}
			else{
				ans[i]=0;
			}
		}
	}
	else{
		for(int i=t2;i>=0;i--){
			if(b[i]!=a[i]){
				ans[i]=1;
			}
			else{
				ans[i]=0;
			}
		}
	}
	int cnt=0;
	for(int i=max(t1,t2);i>=0;i--){
		cnt*=2;
		cnt+=ans[i];
		cnt%=mod;
	}
	return cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		long long x;
		cin>>x;
		x%=mod;
		s[i]=x;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			if(i==j){
				if(s[i]==k){
					ans++;
				}
			}
			else{
				int g=s[j];
				for(int x=j+1;x<=i;x++){
					g=yh(g,s[x]);
				}
				if(g==k){
					ans++;
					j=i;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}