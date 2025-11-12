#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005],x,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			x=i;
			for(int p=i+1;p<=j;p++){
				x=(x^a[p]);
			}
			if(x==k){
				ans++;
				i=j+1;
			}
			else{
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
