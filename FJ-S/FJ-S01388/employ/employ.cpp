#include<bits/stdc++.h>
using namespace std;
const int N=505;
char s[N];
int p[N];
bool f[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int i;
	for(i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]==1) f[i]=1;
	}
	for(i=1;i<=n;i++){
		cin>>p[i];
	}
	sort(p+1,p+n+1);
	cout<<n;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
