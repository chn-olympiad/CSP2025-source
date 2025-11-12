#include<bits/stdc++.h>
using namespace std;
int n,m,c[666];
long long sum=1;
string a;
int main(){
	freopen("club","r",stdin);
	freopen("club","w",stdout);
	fclose(stdin);
	fclose(stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		sum*=i;
		sum%=998244353;
	}
	cout<<sum;
	return 0;
} 
