#include <bits/stdc++.h>
using namespace std;
int a[200010];
int sum[200010];
bool ans[1010][1010];
int main(){
	freopen ("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=a[i]^sum[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				ans[i][j]=1;
			}
		}
	}
	int sum=0;
	bool f=0;
	for(int i=1;i<=n;){
		for(int j=i;j<=n;j++){
			if(ans[i][j]==1){
				sum++;
				i=j+1;
				f=1;
				break;
			}
		}
		if(f==0){
			i++;
		}
		f=0;
	}
	cout <<sum;
	return 0;
	
} 
