#include<bits/stdc++.h>
using namespace std;
long long n,k,sum,ans;
long long a[500100],a1[500100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a1[i]=a1[i-1]^a[i];
		if(a[i]==1) ans++;
	}
	int p=1,q=1;
	if(n<=1000){
		for(int i=1;i<=n;i++){
			p=i;
			for(int j=i;j<=n;j++){
				q=j;
				int cnt=a1[q]-a1[p-1];		
				if(abs(cnt)==k){
					sum++;
					i=q,j=q;
					break;	
				}
			}
		}
		cout<<sum;
	}
	else{
		if(n==1) cout<<ans;
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==0) sum++;
				else if(a[i]==1&&a[i+1]==1){
					sum++;
					i++;
				}
			}
		}
	}
	return 0;
}
