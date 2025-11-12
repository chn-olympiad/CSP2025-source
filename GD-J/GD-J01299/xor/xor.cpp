#include<bits/stdc++.h>
using namespace std;
int n,m=0;
long long k,a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int s=0;
			for(int l=i;l<=j;l++){
				s^=a[l];
			}
			if(s==k) m++;
		}
	}
	cout<<m/2;
	return 0;
}
