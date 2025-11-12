#include<bits/stdc++.h>
using namespace std;
int n,a[5001],l[5005],z;
void dfs(int k,int m,int s){
	if(k>n+1)
		return;
	if(s>2*m){
//		cout<<"Ñ¡"; 
//		for(int i=1;i<k;i++)
//			cout<<l[i]<<" ";
//		cout<<"×é³É"<<endl; 
		z++;
//		return;
	}
	l[k]=a[k];
	dfs(k+1,max(m,a[k]),s+a[k]);
	l[k]=0;
	dfs(k+1,m,s);
}
int main(){
	freopen("polyon.in","r",stdin);
	freopen("polyon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,0,0);
	cout<<z;
	return 0;
}
