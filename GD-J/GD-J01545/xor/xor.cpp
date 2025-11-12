#include<bits/stdc++.h>
#include<cstdio>
#define ll long long 
using namespace std;

const int N=5*1e5+5;
int n;
ll k,a[N];
int maxx=0;
int find(int l,int r){
	int k=a[l];
	for(int i=l+1;i<=r;i++){
		k=k^a[i];
	}
	return k;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int ans=find(i,j);
			if(ans==k){
				maxx++;
			}	
		}	
	}
	cout<<maxx<<"\n";
	return 0;
} 
