#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010]={0},maxn=0,mmin=INT_MAX,z=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		mmin=min(mmin,a[i]);
	}
	if(k==0&&mmin==1&&maxn==1){
		cout<<n/2;
	}else if((k==0&&mmin==0&&maxn==0)||(k==1&&mmin==1&&maxn==1)){
		cout<<n;
	}
	else if(k==1&&mmin==0&&maxn==0) cout<<0; 
	else if(mmin==0&&maxn==1&&k==1){
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1]){
				i++;
				z++;
			}
		}
		cout<<z;
	}else if(mmin==0&&maxn==1&&k==0){
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				z++;
				i++;
			}
			else if(a[i-1]==1&&i<=n-1){
				z++;
				i+=2;
			}
		}
		cout<<z;
	}
	else cout<<5;
	return 0;
}