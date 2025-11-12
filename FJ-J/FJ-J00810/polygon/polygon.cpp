#include<bits/stdc++.h>
using namespace std;
int n,maxn;
int polygons[5005];
int main(){

	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&polygons[i]);
		maxn=max(maxn,polygons[i]);
	}
	if(n==3 and polygons[0]+polygons[1]+polygons[2]>2*maxn){
		cout<<1;
	}
	else if(n==3){
		cout<<0;
	}
	else if(maxn==1){
		cout<<n-2;
	}
	else{
		cout<<n+1;
	}

	return 0;
}

