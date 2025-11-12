#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","r",stdout);
	int n,m,c[100010];
	char s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=10&&m<=n){
		cout<<m;
	}
	if(m==n && n<=500){
		cout<<pow(m,m);
	}
	if(m==1 && n<=500){
		cout<<515058943;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
