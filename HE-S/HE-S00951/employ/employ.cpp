#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,q=0;
	cin>>n>>m;
	int s[n],c[n];
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=n;i>=n-m;i--){
		q*=i;
	}
	for(int i=1;i<=n;i++){
		q/=i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
