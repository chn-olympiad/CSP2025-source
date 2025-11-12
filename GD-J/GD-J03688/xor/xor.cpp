#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,ans=0,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		ans=a[l];
		for(int r=1;r<=n;r++){
			ans+=(ans^a[r]);
			if(ans==m){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
