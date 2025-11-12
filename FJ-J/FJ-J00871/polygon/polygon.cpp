#include<iostream>
using namespace std;
int n;
int a[5005];
int ans=0;
void dfs(int c,int sum,int maxn,int k,string s){
	if(n-k<c)  return;
	s+=to_string(a[k])+" ";
	maxn=max(maxn,a[k]);
	sum+=a[k];
	c--;
	if(c==0){
		if(sum>maxn*2){
			ans=(ans+1)%998244353;
			//cout<<s<<endl;
		}
		return;
	}
	for(int i=k+1;i<n;i++)
		dfs(c,sum,maxn,i,s);
}
int main(){
	freopen("polygon4.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=3;i<=n;i++)
		for(int j=0;j<n;j++)
			dfs(i,0,-1,j,"");
		
	cout<<ans;
}

