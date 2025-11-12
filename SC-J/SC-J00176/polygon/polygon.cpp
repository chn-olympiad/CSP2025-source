#include<bits/stdc++.h>
using namespace std;
int l[5005];
/*bool chack(int m,int i){
	int sum=0,maxi=0;
	if(m>=3){
		for(int i=1;i<=m;i++){
			maxi=max(l[i],l[i]-1);
			sum+=l[i];
		}
		if(maxi*2<sum) return 1;
		else return 0;
	}
	else return 0;
}*/
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	//sort(l+1,l+1+n);
	if(n==3){
		int sum=0,maxn=-1;
		for(int i=1;i<=n;i++){
			sum+=l[i];
			maxn=max(maxn,l[i]);
		}
		if(maxn*2<sum) cout<<1;
		else cout<<0;
	}
	return 0;
}