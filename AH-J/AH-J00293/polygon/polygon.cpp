#include<bits/stdc++.h>
using namespace std;
int n,m=2;
int a[5010];
int b[5010];
int sum=0,ans=0,anss=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		int tot=0;
		for(int i=1;i<=n;i++){
			tot=max(tot,a[i]);
			sum+=a[i];
		}
		if(sum>tot*2){
			ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	while(m++){
		if(m>n){
			break;
		}
		int tot=0;
		for(int k=1;k<=n-2;k++){
			int j=0;
			for(int i=anss;i<=n;i++){
				if(j==m){
					break;
				}
				j++;
				b[i]=a[i];
				sum+=b[i];
				tot=max(b[i],tot);
			}
			anss++;
			if(sum>tot*2)ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
