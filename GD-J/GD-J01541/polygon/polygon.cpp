#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],ans=0,i;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<pow(2,n);i++){
		long long i_=i,cnt=1,maxn=0,sum=0,cnt1=0;
		while(i_){
			if(i_%2==1){
				maxn=max(maxn,a[cnt]);
				sum+=a[cnt];
				cnt1++;
			}i_/=2;
			cnt++;
		}if(sum>2*maxn&&cnt1>=3)ans++;
	}cout<<ans%998244353;
	return 0;
}
