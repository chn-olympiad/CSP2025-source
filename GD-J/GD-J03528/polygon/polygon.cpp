#include<bits/stdc++.h> 
using namespace std;
//deque;
//vetor;
bool kk[1000000][6000];
long long n,k[6000],b[6000],maxx=0,m=0,sum=0;
struct zzh{
	long long si=0;
	long long id;
}a[6000];
long long sq(long long x,long long y){
	long long sq2=1;
	for(long long i=1;i<=y;i++){
		sq2=sq2*(x-i+1)/i;
	}
	return sq2;
}
void zn(long long i,long long ans,long long sum2,long long maxxx){
	if(maxxx*2<ans&maxxx!=0){
		if(!kk[ans][maxxx])sum+=sum2;
		sum=sum%998244353;
		kk[ans][maxxx]=true;
//		cout<<maxxx<<" "<<ans<<"\n";
	}
	if(i>=m)return;
	for(long long o=0;o<=a[i].si;o++){
		if(o!=0)maxxx=a[i].id;
		zn(i+1, ans+o*a[i].id , sum2*sq(a[i].si,o)%998244353 ,maxxx);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=0;i<n;i++){
		scanf("%lld",&b[i]);
		maxx=max(maxx,b[i]);
		k[b[i]]++;
	}
	sort(b,b+n);
	long long ans=0;
	for(long long i=0;i<n;i++){
		ans++;
		if(b[i]!=b[i+1])a[m].id=b[i],a[m++].si=ans,ans=0;
	}
	zn(0,0,1,0);
	cout<<sum;
	return 0;
}
