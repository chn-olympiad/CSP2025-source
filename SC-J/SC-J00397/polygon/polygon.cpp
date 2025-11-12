#include<bits/stdc++.h>
using namespace std;

int n,a[10005],sum,maxn;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=3;i++){
		scanf("%d",&a[i]);
		maxn=max(maxn,a[i]);
		sum+=a[i];	
	}
	if(sum>2*maxn){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
} 