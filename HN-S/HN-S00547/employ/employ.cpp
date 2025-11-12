#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int mod=998244353;
int c[N];
int n,m;
int p;
char s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='1') p++;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int x=1;
	for(int i=1;i<=p;i++){
		x=(x*i)%mod;
	}	
    cout<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
