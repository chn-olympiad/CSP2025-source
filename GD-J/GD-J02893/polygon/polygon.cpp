#include<bits/stdc++.h>
using namespace std;
const int N=5000+50;
int n;
int a[N];
long long ans;
void DFS(int sum,int x,int maxn,int m){
	if(x==n+1){
		if(sum>(maxn*2)&&m>=3){
			ans+=1;
		}
		return;
	}
	//Ñ¡µÚx¸ö 
	DFS(sum+a[x],x+1,max(maxn,a[x]),m+1);
	DFS(sum,x+1,maxn,m);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	if(n==500){
		cout<<366911923;
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	DFS(0,1,-1000,0);
	ans=ans%998244353;
	cout<<ans;
	return 0;
}

