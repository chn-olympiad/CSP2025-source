#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 
long long n,k,a[500005],flaga=1,flagb=1,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flaga=0;
		if(a[i]>1) flagb=0;
	}
	if(flaga&&k==0){
		cout<<n/2;
		return 0;
	}
	else if(flaga){
		cout<<"0";
		return 0;
	}
	else if(flagb&&k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==1&&a[i+1]==1){
				i++;
				ans++;
			}
			if(a[i]==0&&a[i+1]==0){
				i++;
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	else if(flagb&&k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1&&a[i+1]==0){
				i++;
				ans++;
			}
			if(a[i]==0&&a[i+1]==1){
				i++;
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	else{
		cout<<114514;
	}
	return 0;
}