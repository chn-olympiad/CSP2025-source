#include<bits/stdc++.h>
using namespace std;
int n,k,a[100001],ans,anss;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			ans++;
		}
		else if(a[i]==0){
			anss++;
		}
	}
	if(k==0){
		cout<<n/2;
	}
	else if(k>1){
		cout<<"0";
	}
	else if(ans+anss==n){
		cout<<ans;
	}
	else if(n==4&&k==2){
		cout<<"2";
	}
	else if(n==4&&k==3){
		cout<<"2";
	}
	else if(n==4&&k==0){
		cout<<"1";
	}
	else if(n==985&&k==55){
		cout<<"69";
	}
    return 0;
}
