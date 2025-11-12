#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000001],maxn=0,maxh=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);    	
	}
	int x=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<i+m;j++){
			x=(x|j);
		}
		maxh=max(maxh,x);
	}
	cout<<max(maxn,maxh);
	return 0;
}
