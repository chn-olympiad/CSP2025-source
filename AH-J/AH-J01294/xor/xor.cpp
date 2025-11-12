#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int r=1,sum=0;
	int cnt=0;
	for(int l=1;l<=n;l++){
		r=l;
		sum=a[r];
		while(r<=n&&sum!=k){
			r++;
			sum=(a[r]^sum);
		}
		if(sum==k){
			l=r;
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
