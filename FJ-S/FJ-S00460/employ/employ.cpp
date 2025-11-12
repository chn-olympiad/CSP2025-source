#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,a[520],na[520],f[520],nn[520];
string s;
void dfs(int x,int sum,int wh,int fq){
	bool flag=true;
//	cout<<wh<<" "<<na[wh]<<" "<<a[x]<<" ";
	if(na[wh]==1 && a[x]>fq)
		sum+=1;
	else
		fq+=1;
	if(fq>n-m)
		return ;
//	cout<<x<<" "<<sum<<" "<<wh<<" "<<fq<<endl;
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			dfs(i,sum,wh+1,fq);
			f[i]=0;
			flag=false;
		}
	}
	if(flag==true && sum>=m)
		ans=(ans+1)%998244353;//cout<<"!#@@@"<<endl;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		na[i]=s[i-1]-'0';
		nn[i]=nn[i-1]+1-na[i];
//		cout<<na[i]<<" ";
	}
	for(int i=1;i<=n;i++){
		f[i]=1;
		dfs(i,0,1,0);
		f[i]=0;
	}
	cout<<ans<<endl;
	return 0;
}
