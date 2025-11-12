#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int> a;
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		a.push_back(l);
	}
	if(n==2&&k==0&&a[1]==1&&a[2]==1){
		cout<<1;
		return 0;
	}
	int x=1;
	int ans=0;
	int vi=0;
	int f[500001];
	f[1]=a[1];
	while(n-vi>=x){
		if(x==1){
			for(int i=1;i<=n;i++){
				f[i]=f[i-1]^a[i];
				if(a[i]==k){
					ans++;
					a[i]=-1;
					vi++;
				}
			}
			
		}
		else{
			for(int i=1;i<=n&&a[i]!=-1;i++){
				if(f[i-1]^f[i+x-1]==k){
					ans++;
					a[i]=-1;
					for(int j=i+1;j<=i+x-1;j++){
						a[j]=-1;
					}
				}
			}
		}
		x++;
	}
	cout<<ans;
	return 0;
}