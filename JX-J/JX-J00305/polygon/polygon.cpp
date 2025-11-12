#include<bits/stdc++.h>
using namespace std;
int b[50000],j,c[50000];
long long h;
bool cmp(int x1,int y1){
	return x1>y1;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]==1) j++;
	}
	sort(b+1,b+1+n,cmp);
	if(n==3&&2*(b[1]+b[2]+b[3])>b[1]){
		cout<<1;
	}else if(j==n){
		for(int i=3;i<n;i++){
			h=h+(n-i+2)*(n-i+1)/2;
		}
		h++;
		cout<<h%998244353;
	}
	return 0;
}
