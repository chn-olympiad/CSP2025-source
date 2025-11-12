#include<bits/stdc++.h>
using namespace std;
int mo=998244353;
int n;
long long s,ans;
int a[5050];
int id=0;
bool p[5050];
void dfs(int x,int k,int ma){
	id++;
	if(s>ma&&id>k) ans++,ans%=mo;
    if(id>k) return;
    for(int i=x+1;i<=n;i++)
	{
	      	s+=a[i];
	      	dfs(i,k,ma);
	      	id--;
	      	s-=a[i]; 	
	}
} 
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int k=3;k<=n;k++)
	{
		for(int j=1;j+k-1<=n;j++){
		id=0,s=0;dfs(j,k-1,a[j]);
		}
	}
	cout<<ans%mo<<endl;
	return 0;
}
