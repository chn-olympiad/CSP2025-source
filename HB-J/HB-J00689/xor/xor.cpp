#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans[5],book[500005],sum;
int f1,f2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans[a[i]]++;
		if(a[i]==0) f1=1;
		if(a[i]>1) f2=1;
	}
	if(!f2){
		if(!f1){
			if(k==1) cout<<ans[1];
			else cout<<ans[1]/2;
			return 0;
		}
		else{
			if(k==1) cout<<ans[1];
			else{
				for(int i=2;i<=n;i++){
					if(a[i]==1&&a[i-1]==1&&book[i-1]==0){
						sum++;
						book[i]=1;
					}
				}
				cout<<ans[0]+sum;
			}
		}
	}
	return 0;
}
