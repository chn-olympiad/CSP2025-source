#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int const maxn=2e5+5;
int n, m ,k,a[maxn][maxn][maxn];
int main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cout<<n+m+k;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
