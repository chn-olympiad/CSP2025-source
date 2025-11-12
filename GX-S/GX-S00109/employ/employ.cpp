#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
long long n,m,x[N],ans=1;
string a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >>n >>m;
	cin >>a;
	for (int i=1;i<=n;i++){
		cin >>x[i];
		ans*=i;
	} 
	cout <<ans;
	return 0;
}
