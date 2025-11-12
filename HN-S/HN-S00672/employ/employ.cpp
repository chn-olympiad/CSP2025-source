#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],ans=0;
string q;
int b[1000],f[1000];
int pd(){
	int sum=0,s[1000],r=0;
	for(int i=1;i<=n;i++) s[i]=a[i];
	for(int i=1;i<=n;i++){
		s[b[i]]-=r;
		if(s[b[i]]==0) r++;
		if(q[i-1]=='0') r++;
		if(q[i-1]=='1'&&s[b[i]]>=1) sum++;
		
	}
	return sum==m? 1:0;
}
void yzc(int x){
	if(x==n){
		ans+=pd();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			b[x+1]=i;
			yzc(x+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	memset(f,0,sizeof(f));
	cin>>n>>m;
	cin>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	yzc(0);
	cout<<ans%998244353;
	return 0;
}  
