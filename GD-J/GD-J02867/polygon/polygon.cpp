#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long n,a[5050],flag1=1,ans;
int kuaisumi(long long x,long long y){
	long long ans=1,cnt=x;
	while(y){
		if(y%2){
			ans=(ans*cnt)%MOD;
		}
		cnt=(cnt*cnt)%MOD;y/=2;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)flag1=0;
	}
	if(flag1){
		cout<<kuaisumi(2,n)-n*(n+1)/2-1;
	}
	else{
		for(int i=0;i<(1<<n);i++){
			long long x=i,maxn=0,sum=0,now=1;
			while(x){
				if(x%2){
					maxn=max(a[now],maxn);
					sum+=a[now];
				}
				now++;x/=2;
			}
		    if(maxn*2+1<=sum)ans++;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
} 
