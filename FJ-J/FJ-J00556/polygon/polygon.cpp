#include<bits/stdc++.h>
using namespace std;
long long sum=0;
int a[5010]={},b[5010]={},m=0;
void hhh(int k,int n,int p){
	if(p==n){
		int q=0;
		for(int i=0;i<m;i++){
			q+=b[i];
		}
		if(q>b[p-1]*2){
			sum++;
		}
		return;
	}
	for(int i=k;i<=m-1;i++){
		i++;
		if(i<=m){
			b[p]=a[i];
		}
		p++;
		hhh(i,n,p);
		p--;
		i--;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin>>n;
	m=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int j=3;
	while(n-2!=0){
		hhh(0,j,0);
		if(sum>998244353){
			sum-=998244353; 
		}
		j++;
		n--;
	}
	cout<<sum;
	return 0;
}
