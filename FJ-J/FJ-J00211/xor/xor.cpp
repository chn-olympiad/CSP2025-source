#include<bits/stdc++.h>
using namespace std;
int n,k,a[100010],l,y,lxdy;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) l++;
		if(a[i]==1) y++;
	}
	for(int i=1;i<=n;i+=2){
		if(a[i]==1 && a[i+1]==1) lxdy++; 
	}
	if(k==0) cout<<l+lxdy;
	else cout<<y;
	return 0;
}
