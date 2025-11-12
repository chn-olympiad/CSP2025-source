#include<bits/stdc++.h>
using namespace std;
long long n,t,a[50001],b[50001],anss;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;return 0;
	}
	for(long long i=1;i<=n;i++){
		cin>>a[i];b[a[i]]++;
	}
	if(b[1]==n){
		anss=0;
		for(long long i=3;i<=n;i++){
			long long t1=1,t2=1;
			
			for(long long j=1;j<=i;j++){
				t2*=j;
				t1*=n-i+1;
			}
			anss+=t1/t2;
		}
		cout<<anss;
		return 0;
	}
	/*for(long long i=1;i<=n;i++){
		
	}*/
	return 0;
}

