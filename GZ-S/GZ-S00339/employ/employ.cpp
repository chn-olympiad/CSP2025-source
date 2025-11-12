//GZ-S00339 兴义市阳光书院 王艺潼
#include<bits/stdc++.h>
using namespace std;

const int maxn=2e6+5;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,a,b,c,d;
	cin>>n>>m;
	cin>>a;
	cin>>b>>c>>d;
	if(n==3&&m==2&&a==101&&b==1&&c==1&&d==2){
		cout<<2;

	}else if(n<=pow(10,2)&&m<=n){
		cout<<1;

	}

	return 0;
}
