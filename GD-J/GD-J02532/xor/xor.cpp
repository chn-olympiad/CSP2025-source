#include<bits/stdc++.h>
using namespace std;
int a[500005],dp[50005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int j;
	for(int i=0;i<n;i++){
		int xors=0;
		for(j=i;j<n;j++){
			xors=xors^a[j];
			if(xors==k){
				ans++;
				i=j;
				break;
			}
			if(j==n-1 && xors!=k){
				break;
			}
		}
	} 
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
