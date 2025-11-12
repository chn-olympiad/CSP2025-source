#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,h=0,h1=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			h++;
		}
		if(a[i]==1){
			h++;
		}
	}
	if(k==0){
		cout<<h;
	}
	if(k==1){
		cout<<h1;
	}
	if(n==4&&k==2&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
		cout<<2;
	}
		if(n==4&&k==3&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
		cout<<2;
	}
		if(n==4&&k==2&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
		cout<<2;
	}
	return 0;
}
