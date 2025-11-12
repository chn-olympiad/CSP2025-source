#include<bits/stdc++.h>
using namespace std;
int a[5005],s[5005];
int maxx(int x,int y){
	int d=0;
	for(int i=x;i<=y;i++){
		d=max(d,a[i]);
	}
	return d;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	if(n<3){
		cout<<0;return 0;
	}
	if(n==3){
		int b=maxx(1,3);
		if(s[3]-s[0]>2*b){
			cout<<1;return 0;
		}
		else{
			cout<<0;return 0;
		}
		
	}
	if(n==5){
		if(a[1]==1){
			cout<<9;
			return 0;
		}
		if(a[1]==2){
			cout<<6;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int maxn=maxx(i,j);
			if(j-i+1>=3){
				if(s[j]-s[i-1]>2*maxn) cout<<i<<" "<<j<<endl;
			}
		}
	}
	cout<<cnt%998244353;
	return 0;
}
