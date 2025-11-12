#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
bool f;
int ans;

bool check(int c,int x,int xia){
	if(f){
		return f;
	}
	if(xia>n){
		return 0;
	}
	if(c>x){
		f=1;
		return f; 
	} 
	for(int l=xia+1;l<=n;l++){
		for(int r=l+1;r<=n;r++){
			if((l==n||r==n)&&c<x){
				xia=n+1;
				return 0; 
			} 
			int cnt=(a[l]^a[l+1]);
			for(int i=l+2;i<=r;i++){
				cnt=(cnt^a[i]);
			}
			if(cnt==k){
				check(c+1,x,r);
				if(f){
					return f;
				}
			}
		}
	}
}

void fen(int l,int r){
	f=0;
	int mid=(l+r)/2;
	if(mid==l){
		cout<<mid;
		exit(0);
	}
	if(check(1,mid,0)){
		fen(mid+1,r); 
	} 
	else{
		fen(l,mid);
	} 
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	fen(1,n);
	return 0; 
}