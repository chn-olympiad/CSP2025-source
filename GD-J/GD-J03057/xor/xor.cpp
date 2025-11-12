#include<bits/stdc++.h>
using namespace std;
int n,k,xors,ans,l,r;
int main(){
	ios::sync_with_stdio(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,xors,ans=0;
	cin>>n>>k;
	vector<int>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	for(l=0;l<n;l++){
		for(r=l;r<n;r++){
			xors=v[r];
			for(int i=l;i<r;i++){
				xors^=v[i];
			}
			if(xors==k){
				ans++;
			}
		}
	}
	cout<<ans;
}
