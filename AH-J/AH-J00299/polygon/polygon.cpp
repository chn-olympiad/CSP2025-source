#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N];
long long hs(long long x,long long y){
	long long l=1;
	long long sum=1;
	while(l<=x){
		sum*=(y-l+1);
		l++;
	}
	l=1;
	while(l<=x){
		sum/=l;
		l++;
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnt++;
		}
	}
	sort(a+1,a+n+1);
	if(n<3){
		cout<<"0";
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2){
			cout<<"1";
			return 0;
		}else{
			cout<<"0";
			return 0;
		}
	}
	if(cnt==n){
		long long sum=0;
		for(int i=3;i<=n;i++){
			sum+=hs(i,n);

			sum%=998244353;
		}
		cout<<sum;
	}else{
		cout<<"0";
	}
	return 0;
}
