#include<bits/stdc++.h>
using namespace std;

int n,m,c[505],a,b;
string s;

int f(int x){
	int sum=2;
	for(int i=3;i<=n;++i) sum*=3;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;++i){
		scanf("%d",c[i]);
		a+=c[i];
	}
	for(int i=1;i<=n;++i) b+=s[i]-'0';
	if(c[i]>=n*(n-1)) printf("%d",f(n));
	else if(c[i]=0 && b<m) printf("0");
	else if(b==0) printf("0");
	else if(b==n) printf("%d",f(n));
	return 0;
}
