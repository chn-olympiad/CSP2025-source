#include<bits/stdc++.h>
using namespace std;
int s=0,n,a[5001],sum,book[5001];
void DFS(int maxn,int n,int m){
	if(sum>a[maxn]&&n>=3){
		s++;
		if(n==maxn){
			return;
		}
	}
	for(int i=m;i<maxn;i++){
		if(book[i]!=1){
			sum+=a[i];
			book[i]=1;
			DFS(maxn,n+1,i);
			sum-=a[i];
			book[i]=0;
		}
	}return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(book,sizeof(book),0); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		DFS(i,1,1);
	}
	cout<<s%998244353;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}