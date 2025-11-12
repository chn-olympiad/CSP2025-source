#include<bits/stdc++.h>
using namespace std;

long long mod=998244353;
long long n,a[5005];
long long an,ans[5005];

void cz(long long fir,long long x,long long sum,long long cnt,long long summ){
	if(cnt>2){
//		cout<<fir<<" "<<x<<' '<<sum<<' '<<cnt<<"\n";
		ans[fir]=(ans[fir]+1)%mod;
	}
	if(x>n)
		return;
	for(int i=x;i<=n;i++){
		if(cnt<2)
			cz(fir,i+1,sum,cnt+1,summ+a[i]);
		else if(summ+a[i]>a[i]*2)
			cz(fir,i+1,(sum+1)%mod,cnt+1,summ+a[i]);	
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n-2;i>0;i--)
		cz(i,i,0,0,0);
	for(int i=1;i<=n;i++)
		an=(an+ans[i])%mod;
	cout<<an;
	return 0;
} 
