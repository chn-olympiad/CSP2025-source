#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int m[1000001];
int a1[1000001];
int n;
int k;
long long sum;
int z=1;
void panduan(){
	sort(m+1,m+k+1);
	long long int num=0;
	for(int i=1;i<=k;i++)num+=m[i];	
	if(num>m[k]*2)sum++;
}
void dfs(int q,int p){
	if(q==p+1){
		k=q-1;
		panduan();
		return;
		}
	for(int i=1;i<=n;i++){
		if(m[z-1]>a[i])continue;
		if(a1[i]!=1){
			m[z]=a[i];
			z++;
			a1[i]=1;
			dfs(q+1,p);
			a1[i]=0;
			z--;
		}	
	}
}
int main(){
	freopen("ploygon.in","r",stdin);
	freopen("ploygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int d=3;d<=n;d++){
		for(int j=1;j<=n;j++){m[j]=0;a1[j]=0;}
		dfs(1,d);
	}
	cout<<sum%998244353;
	return 0;
}
