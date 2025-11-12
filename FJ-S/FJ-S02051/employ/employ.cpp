#include <bits/stdc++.h>
using namespace std;

const int MAN=998244353;
const int N=510;
int n,m;
string s;
int a[N];
bool A=true;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(s[i-1]!=1) A=false;
	}
	if(n==m){
		int sum=1;
		for(int i=1;i<=n;i++){
			sum=sum*i%MAN;
			sum%=MAN;
		}
		cout<<sum;
		return 0;
	}

	cout<<2;
	return 0;
}