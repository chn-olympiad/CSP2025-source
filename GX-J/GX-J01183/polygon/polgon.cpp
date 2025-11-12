include<bits/c++.h>
using namespace std;
freopen(stdin,"r",polgon.in);
freout(stdout,"w",polgon.out);
long long jik(long long max,long long a[n]){
	max=-1;
	for(int i=0;i<=n;i++){
		if(max<a[i]){
			max=a[i];
		}
	}
	return max;
}
int main(){
	long long n,m,l[234221345],k=0,lk;
	cin>>n;
	long long a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++){
		long long f=3;
		while(f<=n){
			for(int b=1;b<=f;b++){
				m=a[i]+a[i+1];
				l[i]=a[i];
				l[i+1]=a[i+1];
			}
			if(jik(lk,l)*2<m){
				k++
			}
			f++;
		}
	}
	cout<<k;
	return 0;
}

