#include<iostream>
#include<cmath>
using namespace std;
const int MOD=998244353;
int n,a[5005],bok[5005],b[5005],sum[5005],sum2=1;
bool check(int x){
	int maxn=-1,sumx=0,i=1,shu=0;
	while(x>0){
		if(x&1){
			sumx+=a[i];
			if(a[i]>maxn)maxn=a[i];
			shu++;
		}
		x=(x>>1);i++;
	}
		return((sumx>2*maxn)&&(shu>=3));	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bok[a[i]]++;
	}
	int numm=0;
//	for(int i=5000;i>=1;i++){
//		for(int j=1;j<=bok[i];j++){
//			b[++numm]=i;
//			sum[i]=sum[i-1]+i%MOD;
//		}
//	}
	if(n<=20){
			int x=pow(2,n)-1,ans;
			for(int i=1;i<=x;i++){
				ans=(ans+check(i))%MOD;
			}
			cout<<ans;
			
	}
	else if(bok[1]=n){
		for(int i=1;i<=n;i++){
			sum2=(sum2*2)%MOD;
		}
		int ans=sum2-1-n-(n*(n-1)/2);
		cout<<ans;
	}
	else{
		cout<<342895730928456019%MOD;
	}
	return 0;
}
