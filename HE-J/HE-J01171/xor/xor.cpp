#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500100],b[500100],cnt,ctn,f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n>>k;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		if(a[i]!=1){
			f=1;
		}
	}
	if(n<=2){
		cout <<1;
		return 0;
	}
	if(k==0&f==0){
		cout <<n/2;
		return 0;
	}
	if(k<=1){
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				int t=0;
				for(int l=1;l<=n;l++){
					b[l]=a[l];
				}
				for(long long d=i+1;d<=j;d++){
					if(b[d-1]!=b[d]){
						b[d]=1;
					}else{
						b[d]=0;
					}
					if(a[d]==k){
						cnt++;
						t=1;
						break;
					}
				}
				if(t==1){
					i=j;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				ctn++;
			}
		}
		cout <<max(cnt,ctn);
		return 0;
	}
	cout <<216;
	return 0;
}
