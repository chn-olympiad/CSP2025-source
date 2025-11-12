#include<bits/stdc++.h>
using namespace std;
int n,m,c[502],c0=0,ans=0;
string s;
int stair(int x){
	int q=1;
	for(int i=x;i>=1;i--){
		q*=i;
	}
	return q;
}
void a(int m,int n){
	for(int i=n;i>=m;i--){
		ans+=stair(n)/stair(n-i);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i;i<n;i++){
		cin>>c[i];
		if(c[i]==0) c0++;
	}
	for(;m<=n-c0;m++){
		ans+=stair(m);
	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
