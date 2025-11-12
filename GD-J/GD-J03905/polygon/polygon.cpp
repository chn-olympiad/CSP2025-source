#include<bits/stdc++.h>
using namespace std;
int ans=0,ma=0;int s[5555];
void dg(int sum,int dep){
	if(sum>ma){
		ans++;
	}
	for(int i=dep;i>=1;i--){
		dg(sum+s[i],i-1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	for(int i=3;i<=n;i++){
		ma=s[i];
		dg(0,i-1);
	}
	cout<<ans;
	return 0;
}
//อหาÛมหนþนþ 
