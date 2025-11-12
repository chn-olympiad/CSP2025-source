//GZ-S00320 贵阳市第一中学 王文彬 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a,s=1;
string f;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>f;
	for(int i=1;i<=n;i++){
		cin>>a;
		s*=i;
	}
	cout<<s%998244353<<endl;
	return 0; 
}

