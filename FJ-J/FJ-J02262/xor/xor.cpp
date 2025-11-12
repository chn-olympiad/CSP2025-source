#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],sum;
bool yq[500005];
long long xor2(long long g,long long h){
	bool b[25]={0},c[25]={0},bc[25]={0};
	int cnt1=0,cnt2=0,sum=0;
	while(g!=0){
		b[cnt1]=g%2;
		g/=2;
		cnt1++;
	}
	while(h!=0){
		c[cnt2]=h%2;
		h/=2;
		cnt2++;
	}
	int cnt=max(cnt1,cnt2);
	for(int i=0;i<cnt;i++){
		bc[i]=(b[i]+c[i])%2;
	}
	for(int i=cnt-1;i>=0;i--){
		sum*=10;
		sum+=bc[i];
	}
	return sum;
}
bool xor1(long long d,long long e){
	if(d==e&&a[d]==k){
		return 1;
	}else if(d<e){
		long long f=0,f_sum=0;
		for(int i=d;i<=e;i++){
			if(yq[i]==0){
				f=xor2(f,a[i]);
			}else{
				return 0;
			}
		}
		int cnt=0;
		while(f!=0){
			f_sum+=(f%10)*pow(2,cnt);
			f/=10;
			cnt++;
		}
		return f_sum==k;
	}else{
		return 0;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sum1=sum;
			sum+=xor1(i,j);
			if(sum1=sum){
				for(int l=i;l<=j;l++){
					yq[l]==1;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
