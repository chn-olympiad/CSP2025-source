#include<bits/stdc++.h>
using namespace std;
int n,k,a[5005],xorands[5005][5005],ans=-9999;
int calm(int l,int r){
	int sum=a[l];
	for(int i=l+1;i<=r;i++){
		sum^=a[i];
	} 
	return sum;
}
void init(){
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			xorands[l][r]=calm(l,r);
		}
	}
}
void xorand(int l,int r,int cnt){	
	if(xorands[l][r]==k){
		cnt++;
		if(r==n){
			ans=max(ans,cnt);
			return;
		}
		xorand(r+1,r+1,cnt);
		cnt--;
	}
	if(r==n){
		ans=max(ans,cnt);
		return;
	}
	for(int i=1;i<=n-r;i++){
		xorand(l,r+i,cnt);
	}
	xorand(l+1,l+1,cnt);
	return;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	init();
	int l=1,r=1;
	xorand(1,1,0); 
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
