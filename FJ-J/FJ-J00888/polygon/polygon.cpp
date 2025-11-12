#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10,P=998244353;
int n,a[N],cnt[N],sum,ans;

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cnt[a[1]]++;
	cnt[a[2]]++;
	cnt[a[1]+a[2]]++;
	sum=3;
	for(int i=3;i<=n;i++){
		int p=0;
		for(int j=1;j<=a[i];j++){
			p=(p+cnt[j])%P;
			
		}
		ans=(ans+sum-p+P)%P;
	//	for(int j=1;j<=10;j++)cout<<cnt[j]<<' ';
		
		for(int j=N;j>=a[i];j--){
			cnt[j]=(cnt[j]+cnt[j-a[i]])%P;
			
		}cnt[a[i]]++;
		int w=0;
		sum=(sum*2+1)%P; 
		
	}
	cout<<ans;
	return 0;
}

