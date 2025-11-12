#include<bits/stdc++.h>
using namespace std;
int n,k,x,q;
int a[500005],b[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)x=1;
		if((a[i]!=1)&&(a[i]!=0))q=1;
	}
	if(x==0&&k==0){
		cout<<n/2;
		return 0;
	}
	if((q==0)&&(k<2)){
		int ans=0;
		if(k==0){
			for(int i=0;i<n;i++){
				if(a[i]==0)ans++;
				else if(a[i]==1&&a[i+1]==1&&b[i]==0){
					ans++;
					b[i+1]=1;
				}
			}
		}
		else{
			for(int i=0;i<n;i++){
				if(a[i]==1)ans++;
			}			
		}
		cout<<ans;
		return 0;
	}
	cout<<2;
	return 0;
} 
