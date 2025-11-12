#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],sum,b=INT_MIN;
void aa(int bi,int sh,int cnt){
	if(sh==0){
		sum++;
		sum%=998244353;
		return;
	}
	for(int i=bi;i<=n-sh+1;i++){
		if(sh==1){
			if(a[i]>=cnt){
				return;
			}
		}
		aa(i+1,sh-1,cnt+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b=max(b,a[i]);
	}
	if(b==1){
		long long c=1;
		for(int i=3;i<=n;i++){
			sum+=c;
			sum%=998244353;
			c=2*c+i-1;
			c%=998244353;
		}
		cout<<sum;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		aa(1,i,0);
	}
	cout<<sum;
	return 0;
}