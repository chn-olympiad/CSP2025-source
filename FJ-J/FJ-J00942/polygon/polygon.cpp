#include<bits/stdc++.h>
using namespace std;
long long a[10010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,m=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=3;i<=n;i++){
		for(long long j=i;j<=n;j++){
			for(long long k=i-1;k<j;k++){
				for(long long l=i-2;l<k;l++){
					if(k+l>k){
						m++;
					}
				}
			}
		}
	}
	cout<<m;
	return 0;
}
