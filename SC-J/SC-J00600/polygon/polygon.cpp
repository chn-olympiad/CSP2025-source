#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n,l,r;
int a[5001],k[5501];
bool t[5001];
long long ans,pop,sum;
inline void dfs(int x){

if(ans>pop*2||x>n){
		if(ans>pop*2&&pop==k[x-1]){
		
			sum++;
			sum%=998244353;
		}
	if(x>n)
	return;
	}
		r=l;
	for(int i=l+1;i<=n;i++){
		if(t[i]==0){
			ans+=a[i];
			pop=max(pop,(long long )a[i]);
	
			t[i]=1;
		k[x]=a[i];
		l=i;
	
			dfs(x+1);
			l=r;
		
			pop=0;
			ans-=a[i];
			t[i]=0;
		}
}
	return ;
		
	
}
int main(){	
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
 cin>>n;
 
 for(int i=1;i<=n;i++){
scanf("%d",&a[i]);
 	
 	
 }
 for(int i=1;i<=n;i++){
 	for(int j=1;j<=n;j++){
 		if(a[i]<a[j]){
 			swap(a[i],a[j]);
		 }
	 }
 }
 
 dfs(1);
 cout<<sum;
}