#include <bits/stdc++.h>
using namespace std;
int n,k,a[2005],c[524293],ans;
bool ooo(int i,int j){
	int h=a[i];
	if(c[i]) return 0;
	for(int o=i+1;o<=j;o++){
		if(c[o]) return 0;
		h=h^a[o],c[o]++;
	}
	if(h==k) return 1;
	else{
		for(int o=i;o<=j;o++){
			c[o]=0;
		}
	}
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) ans++,c[i]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(ooo(i,j))ans++;
		}
	}
	cout<<ans;
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////
