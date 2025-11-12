#include<bits/stdc++.h>
using namespace std;
long long a[500001],b[500001]={0};
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long k;
	int n,s=0;
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==k) {
			s++;
			b[i]=1;
		}
	}
	int l=2;
	while(l<=1000) {
		for(int i=1; i<=n-l+1; i++) {
			if(b[i]!=0)continue;
			if(a[i]+a[i+l-1]==k||a[i]-a[i+l-1]==k||a[i+l-1]-a[i]==k){
				s++;
				for(int j=i;j<=i+l-1;i++){
					b[j]=1;
				}
			}	
		}
		l++;
	}
	cout<<s;
	return 0;
}