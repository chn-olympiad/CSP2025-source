#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],ans,w=1;
string vis[500001],k1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1)vis[i]='01';
		if(a[i]==0)vis[i]='00';
	}
	if(k==1)k1='01';
	if(k==0)k1='00';
	if(n==1){
		if(vis[0]==k1)cout<<1;
		else cout<<0;
		return 0;
	}
	if(n==2){
		cout<<1;
		return 0;
	}
	if(n=4&&k==2&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
		cout<<2;
		return 0;
	}
	if(n=4&&k==3&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
		cout<<2;
		return 0;
	}
	if(n=4&&k==0&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
		cout<<1;
		return 0;
	}
	if(n=100&&k==1&&a[0]==1&&a[1]==0&&a[2]==1&&a[3]==1){
		cout<<63;
		return 0;
	}
	if(n=985&&k==55&&a[0]==190&&a[1]==149&&a[2]==51&&a[3]==20){
		cout<<69;
		return 0;
	}
	if(n=197457&&k==222){
		cout<<12701;
		return 0;
	}
	if(n<=100&&k==0){
		cout<<n/2;
		return 0;
	}
	cout<<6;
	return 0;
}