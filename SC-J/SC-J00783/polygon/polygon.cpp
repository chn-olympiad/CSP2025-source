#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5005];
long long s[5005];
long long ans;
long long Sum(int x,int I){
	long long sum=0;
	for(int j=0;j<=I;++j){
		if((x>>j)&1){
			sum+=a[I-j];
		}else if((x>>j)&1==1){
			sum-=a[I-j];
		}
	}
	return sum;
}
int Count(int x){
	int cnt=0;
	while(x){
		if(x&1) cnt++;
		x>>=1;
	}
	return cnt;
}
int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	for(int i=3;i<=n;++i){
		for(int j=1;j<=pow(2,i-1)-1;++j){
			if(Count(j)+1<3) continue;//check_2(j) || 
			//cout<<i<<" "<<j<<endl;
			if(Sum(j,i-1)>a[i]){
				ans++;
				ans%=mod;
			}
		}
	}
	cout<<ans%mod;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
