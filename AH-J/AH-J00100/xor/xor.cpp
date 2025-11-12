#include<bits/stdc++.h>
using namespace std;
int solve(int x,int y){
	bool a[25]={0},b[25]={0},c[25]={0};
	int i=1,j=1;
	while(x){
		a[i]=x%2;
		x/=2;
		i++;
	}
	while(y){
		b[j]=y%2;
		y/=2;
		j++;
	}
	int l=max(i,j);
	for(int m=1;m<=l;m++){
		if(a[m]==b[m])c[m]=0;
		else c[m]=1;
	}
	int ans=0,w=0;
	for(int m=1;m<=l;m++){
		if(!c[m]){w++;continue;}
		int t=pow(2,w);
		w++;
		ans+=t;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500005];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<solve(n,k);
	return 0;
}
