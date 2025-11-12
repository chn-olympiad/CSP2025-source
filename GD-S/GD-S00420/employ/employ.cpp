#include<bits/stdc++.h>
using namespace std;
int n,m;
int x[11],a;
int c[505],ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	sort(c+1,c+1+n);
	for(int i=1;i<n;i++){
		if(c[i]!=c[i+1]) ans++;
	}
	if(c[n]!=c[n-1]) ans++;
	if(ans>=m) printf("1");
	else printf("0");
	return 0;
}
