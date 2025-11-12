#include <bits/stdc++.h>
using namespace std;
int a[911],n,m,c[91];
string s;
long long ans=0;
int acc,ref=0;
void solve(int a,int b,int u){
	if(u<n){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
			if((i!=a || j!=b) && (i!=b || j!=a))
				solve(i,j,u+1);	
		}
	}
	swap(c[a],c[b]);
	for(int i=1;i<=n;++i){
		if(s[i]=='0' || ref>=c[i])
		ref++;
		else
		acc++;
	}
	if(acc=m)
		ans++;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	cout<<ans<<acc<<ref;
	return 0;
}
