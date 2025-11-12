#include<iostream>
#include<algorithm>
int n,ans=0,a[5001],sum[5001]={0};
using namespace std;
void work1(){
	int summ=a[1]+a[2]+a[3];
	int maxn=0;
	for(int i=1;i<=n;i++) if(a[i]>maxn) maxn=a[i];
	maxn*=2;
	if(summ>maxn) ans++;
	cout<<ans<<endl;
}
void work2(){
	for(int i=3;i<=n;i++){
		int nn=n,anss=1,aans=1;
		for(int j=1;j<=i;j++){
			anss=(anss*(nn%998244353))%998244353;
			aans=(aans*(j%998244353))%998244353;
			nn--;
		}
		
		ans=(ans+(anss%998244353))%998244353;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==3){ work1(); return 0;}
	sort(a+1,a+1+n);
	if(a[n]==1){ work2(); return 0;}
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	return 0;
}
