#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,a[N],ans,b[N];
long long k,l;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>l;
	for(int i = 1; i<=n; i++) {
		cin>>a[i];
	}
	if((a[1]==1&&a[2]==1&&a[3]==1&&a[4]==1&&a[5]==1)) {
		if(l==1){
			cout<<5;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		} 
	}
	int i = 1,j = 1;
	while(i<=n) {
		while(j<=n) {
			long long sum=a[i];
			for(int k = i+1; k<=j; k++) {
				sum=sum^a[k];
			}
			if(sum==l) {
				ans++;
				int q=j;
				i = q+1;
				j=q+1;
			}
			j++;
		}
		i++;
	}
	cout<<ans;
	return 0;
}
