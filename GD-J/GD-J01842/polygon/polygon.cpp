#include <bits/stdc++.h>
using namespace std;
const long long N=5005;
long long a[N];
long long MOD=998244353;
long long cnt=0,n;
long long f(long long x){
	long long ans=0;
	while(x){
		ans+=(x&1);
		x>>=1;
	}
	return ans;
}
long long f2(long long x){
	long long sum=1;
	while(x){
		sum*=x;
		sum%=MOD;
		x--;
	}
	return sum;
} 
bool check(long long x){
	long long maxn=0,sum=0,c=1;
	while(x){
		if(x&1){
			sum+=a[c];
			maxn=max(maxn,a[c]);
		}
		x>>=1;
		c++;
	}
	if(sum>maxn*2){
		return true;
	}
	return false;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=true;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=false;
		}
	}
	if(flag){
		long long sum=0;
		for(long long i=3;i<=n;i++){
			sum+=f2(n)/(f2(i)*f(n-i)%MOD);
		}
		cout<<sum<<endl;
		return 0; 
	}
	long long B=(1<<n)-1;
	while(B>=0){
		if(f(B)>=3 && check(B)){
			cnt++;
			cnt%=MOD;
		}
		B-=1;
	}
	cout<<cnt<<endl;
	return 0;
}
