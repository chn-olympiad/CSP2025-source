#include<bits/stdc++.h>
using namespace std;
int n,a[114514],k,p,m[114514],t[114514],mag;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	t[1]=1;
	for(int l=1;l<=n;++l){
		m[l]=a[l];
		for(int r=l+1;r<=n;++r){
			m[r]=(m[r-1]^a[r]);
			if(m[r]==k){
				for(int i=1;i<l;i++)mag=max(mag,t[i]);
				t[r]=mag+1;
			}
		}
	}
	cout<<t[n];
	return 0;
}