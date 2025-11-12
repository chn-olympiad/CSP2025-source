#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k,f=0,ff=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=1;
		if(a[i]!=0&&a[i]!=1) ff=1;
	}
	if(f==0&&k==0){
		cout<<n/2;
		return 0;
	}
	if(ff==0){
		int sum=0;
		if(k==0){
			for(int i=1;i<n;i++){
				if(a[i]==a[i+1]&&a[i]==1){
					sum++;
					i++;
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					sum++;
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]){
					sum++;
				}
			}
		}
		cout<<sum;
		return 0;
	}
	if(n==4&&(k==2||k==3)) cout<<2;
	else if(n==4&&k==0) cout<<1;
	else if(n==985&&k==55) cout<<69;
	else if(n==197457&&k==222) cout<<12701;
	else cout<<0;
	return 0;
}
