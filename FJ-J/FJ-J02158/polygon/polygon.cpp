#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],b[5005],s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]+a[i-1];
	}
	for(int i=3;i<=n;i++){
		for(int j=2;j<i;j++){
			for(int k=0;k<=j-2;k++){
				int t=b[j]-b[k];
				for(int l=k;l<=j-2;l++){
					t=t-a[l];
					if(t>a[i]){
						s++;
						s=s%mod;
					}
				}
			}
		}
	}
	cout<<s%mod;
	return 0;
}
