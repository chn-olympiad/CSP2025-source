#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,l,r,x;
	int a[500001];
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x=a[l];
		int cnt=0;
		for(int l=0;l<=n-1;l++){
			for(int r=0;r<=n-1;r++){
				for(int j=l;j<=r;j++){
					x=x^a[j];
				}
			}
		}
		if(x=k)cnt++;
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
