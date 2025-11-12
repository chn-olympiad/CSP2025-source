#include<bits/stdc++.h>
using namespace std;
long long n,a[114514],ans,maxi;
void f1(long long x,long long s,long long m){
	if(x==n+1){
		if(s>2*m)ans=(ans+1)%998244353;
		return ;
	}
	f1(x+1,s,m);
	f1(x+1,s+a[x],max(m,a[x]));
	return ;
}
long long f2(long long x,long long y){
	long long s=1;
	for(long long i=0;y-i>0;i++){
		s=s*(x-i)/(y-i);
	}
	return s;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)scanf("%d",a+i),maxi=max(a[i],maxi);
	sort(a+1,a+n+1);
	if(n<=30){
		f1(1,0,0);
		cout<<ans;
		return 0;
	}
	if(maxi==1){
		for(long long j=3;j<=n;j++){
			ans=(ans+f2(n,j))%998244353;
		}
		cout<<ans;
		return 0;
	}
	return 0;
} 



/*
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5140],b[5140],t,ans;
long long f(long long x,long long y){
	long long s=1;
	for(int i=0;y-i>0;i++){
		s=s*(x-i)/(y-i);
	}
	return s;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(long long i=3;i<=n;i++){
		t=i-2;
		for(long long j=1;j+2<=i;j++){
			if(b[i]-b[j-1]<=2*a[i]){
				t=j-1;break;
			}
		}
		if(t<=0)continue;
		for(long long j=0;j<t;j++){
			ans=(ans+f(t-1,j))%998244353;
		}
		//printf("%d %d %d\n",t,i,ans);
	}
	return 0;
}
*/
