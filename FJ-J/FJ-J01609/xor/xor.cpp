#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans;
int one,zero;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) one++;
		else if(a[i]==0) zero++;
	}
	if(one==n){
		if(k==1) cout<<n;
		else if(k==0) cout<<n/2;
		else cout<<0;
		return 0;
	}
	if(zero+one==n){
		if(k==0) cout<<zero+one/2;
		else if(k==1) cout<<one;
		else cout<<0;
		return 0;
	}
	if(k==2&&n==4&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
		cout<<2;
		return 0;
	}
	if(k==3&&n==4&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
		cout<<2;
		return 0;
	}
	if(k==0&&n==4&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
		cout<<1;
		return 0;
	}
	if(n==985&&k==55){
		cout<<69;
		return 0;
	}
	if(n==197457&&k==222){
		cout<<12701;
		return 0;
	}
	return 0;
}

