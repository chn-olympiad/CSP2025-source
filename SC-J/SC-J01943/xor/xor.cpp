#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<n/2;
	} 
	else if(k==1){
		for(int i=1;i<n;i++){
			if(a[i]!=a[i+1]){
				ans++;
				i++;
			}else if(a[i]==1){
				ans++;
			}
		}
		cout<<ans;
	}
	else{
		int ans=0;
		for(int i=1;i<=n;i++){
			int tans=0;
			int xs=a[i];
			if(xs==k){
				xs=a[i+1];
				tans++;
				i++;
			}
			for(int j=i+1;j<=n;j++){
				xs^=a[j];
				if(xs==k){
					tans++;
					j++;
					xs=a[j+1];
				}
			}
			ans=max(ans,tans);
		}
		cout<<ans;
	}
	return 0;
}