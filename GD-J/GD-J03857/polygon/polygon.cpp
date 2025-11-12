#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n,a[N],ans,x,s[N],ss[N];
bool v[N];
void dfs(int d){
	if(d==x+1){
		int sum=0,ma=0,la=s[0];
		for(int i=0;i<=d-1;i++){
			sum+=s[i];
			ma=max(ma,s[i]);
			
		}
		if(sum>ma*2) ans++;
		return;
	}
	for(int i=ss[d-1];i<=n;i++){
		if(v[i]==false){
			v[i]=true;
			s[d]=a[i];
			ss[d]=i;
			dfs(d+1);
			v[i]=false;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(x=2;x<=n;x++){
		dfs(0);
	}
	cout<<ans/2;
	return 0;
}
