#include<iostream>
using namespace std;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1,r=1;
	for(l=1;l<=n;l++){
		for(r=1;r<=n;r++){
			int m;
			for(int i=l;i<=r;i++){
				m=m|a[i];
				if(m==k){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
