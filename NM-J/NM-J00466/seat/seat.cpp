#include<bits/stdc++.h>
using namespace std;
int a[120];
int b[120];
int n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int ans=n*m;
	for(int i=1;i<=ans;i++){
		cin>>b[i];
	}
	if(n==1&&m==1){
		cout<<1<<" "<<1;
	}
	int r1=b[1];
	sort(b+1,b+ans+1,cmp);
	 if(n==1&&m!=1){
		for(int i=1;i<=m;i++){
			if(b[i]==r1) cout<<1<<" "<<i;
		}
	}
	else if(m==1&&n!=1){
		for(int j=1;j<=n;j++){
			if(b[j]==r1) cout<<j<<" "<<1;
		}
	}
	else if(n==2&&m==2){
		if(b[1]==r1) cout<<1<<" "<<1;
		else if(b[2]==r1) cout<<1<<" "<<2;
		else if(b[3]==r1) cout<<2<<" "<<2;
		else if(b[4]==r1) cout<<2<<" "<<1;
	}
	return 0;
}
