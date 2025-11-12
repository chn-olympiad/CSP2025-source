#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,maxx=-1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int ii=1;ii<=n;ii++){
		for(int i=ii;i<=n;i++){
			int f=0;
			if(a[i]==k){
				ans++;
			
			}
			int sum=a[i];
			for(int j=i+1;j<=n;j++){
				
				if(sum^a[f]==k){
					i=j;
					f=1;
					sum=sum^a[f];
				}else{
					sum=sum^a[f];
				}
			}
			if(f==1){
				ans++;
				
			}
		}
		maxx=max(ans,maxx);
		ans=0;
	}
	cout<<maxx;
	return 0;
}
