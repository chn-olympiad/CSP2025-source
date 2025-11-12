#include<bits/stdc++.h>
using namespace std;
int a[5005];
const int modshu = 998244353;  
bool check(int l,int r){
	if(r-l+1<3) return 0;
	int cnt=0,maxn=INT_MAX;
	for(int i=l;i<=r;i++){
		cnt+=a[i];
		if(a[i]<maxn) maxn=a[i];
	}
	return cnt>2*maxn;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(check(1,3)){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			if(check(i,j)) ans++;
		}
	}
	cout<<ans%modshu;
	return 0;
}
