#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long n,a[6000],w[6000][11000],s,an;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		s+=a[i];
		for(long long j=0;j<=s;j++){
			
			w[i][j]=w[i-1][max((long long)0,j-a[i])]+w[i-1][j];
			if(j<a[i])w[i][j]++;
			w[i][j]%=998244353;
	//		cout<<w[i][j]<<' ';
		}//cout<<'\n';
	}
	
	for(long long i=3;i<=n;i++){
		an+=w[i-1][a[i]];
		an%=998244353;
	}
	cout<<an;
	return 0;
}
