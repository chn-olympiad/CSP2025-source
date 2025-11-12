#include<iostream>
using namespace std;
int mo=998244353;
long long x,n;
long long ans;
long long  a[5005];
long long d[10];
void f(long long k,long long s,long long sum,long long maxn){
	//cout<<sum<<" ";
	if(k>x){
		if(sum>maxn*2){
		   ans=((ans%mo)+(1%mo))%mo;
	   }
		return ;
	}
	for(int i=s+1;i<=n;i++){
			d[i]=a[i];
			long long byj=max(maxn,a[i]);
			f(k+1,i,sum+a[i],byj);
			d[i]=0;
	}
}
				 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool fb=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) fb=1;
	}
	if(!fb){
		int i=0;
		for(int ii=3;ii<=n;ii++){
			if(ii>(n/2+1)){
				i=n-ii;
			}else{
				i=ii;
			}
			long long sum=1;
			for(int j=n;j>=(n-i+1);j++){
				sum*=a[j];
			}
			long long ch=1;
			for(int j=2;j<=i;j++){
				ch*=j;
			}
			long long fa=sum/ch;
			ans=((ans%mo)+(fa%mo))%mo;
		}
		cout<<ans;
	}else{
		for(int i=3;i<=n;i++){
			x=i;
			f(1,0,0,-1);
		}
		cout<<ans;
	}
	return 0;
}
