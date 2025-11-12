#include<bits/stdc++.h>
using namespace std;
char a[510],c[510];
int t;
bool p=false;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) p=1;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) t++;
	}
	if(!p){//Anm
		for(int i=m+1;i<=n-t;i++){
			ans=(ans*i)%998244353;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
