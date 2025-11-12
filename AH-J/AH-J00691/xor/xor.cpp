#include<bits/stdc++.h>
using namespace std;
int a[500005]={0};
int h(int l,int r){
	int k=a[l];
	for(int i=l+1;i<=r;i++){
		k=k^a[i];
	}
	return k;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==1){
		int as=0;
		for(int i=0;i<n;i++){
			if(a[i]==1) as++;
		}
		cout<<as;
		return 0;
	}
	if(k==0){
		int as=0,q=-1;
		for(int i=0;i<n;i++){
			if(a[i]==0){
				as++;
				as+=(i-q-1)/2;
				q=i;
			}
		}
		as+=(n-q-1)/2;
		cout<<as;
		return 0;
	}
	int as=0,q=-1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			if(h(j,j+i-1)==k){
				as++;
				for(int p=j;p<j+i;p++){
					a[p]=q;
					q--;
				}
			}
		}
	}
	cout<<as;
    return 0;
}
