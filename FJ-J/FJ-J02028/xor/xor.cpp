#include<bits/stdc++.h>
using namespace std;
long long n,a[500010],s[500010],k,m;
void dfs(long long l,long long t){
	for(int i=l;i<=n;++i){
		if((s[i]^s[l-1])==k){
			dfs(i+1,t+1);
//			cout<<l<<" "<<i<<" ";
//			cout<<(s[i]^s[l-1])<<"\n";
		}
	}if(t>m){
		m=t;
	}return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
//		cout<<s[i]<<" ";
	}for(int i=1;i<=n;++i){
		dfs(i,0);
	}cout<<m;
	return 0;
}
