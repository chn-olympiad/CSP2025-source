#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum,ans,maxx;
void f(int x,int o){
	if(x==0||o>n){
		if(sum>maxx*2)
		ans++;
		return ;
	}
	for(int i=o;i+x<=n;i++){
		sum+=a[i];
		int c=maxx;
		maxx=max(maxx,a[i]);
		f(x-1,o+1);
		sum-=a[i];
		maxx=c;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n+1-i;j++){
		f(i,j);	
		}
	}
	cout<<ans;
	return 0;
} 
