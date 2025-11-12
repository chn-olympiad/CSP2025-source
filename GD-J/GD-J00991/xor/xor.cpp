#include<bits/stdc++.h>
using namespace std;
long long n,k,a[5000005],x,ans,l=0,m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==m){
			ans++;
			a[i]=-1;
		}
	}
	for(int i=2;i<=n;i++){
		l=0;
		for(int j=1;j<=n;j++){
			if(a[j]==-1)
			l=j;
			else if(j-l>=i){
				x=0;
				for(int k=j;k>j-i;k--){
					x^=a[k];
				}
				if(x==m){
					ans++;
					for(int k=j;k>j-i;k--){
						a[k]=-1;
					}
					l=j;
				}
			}
			
		}
	}
	cout<<ans;
	return 0;
}
