#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
string b; 
int main() {
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin>>n>>m>>b;
	long long sum=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		sum=(sum*i)%998244353;
	}
	cout<<sum;
	return 0;
}/*

4
4 2 1
7 2 4
5 3 4
3 5 1
*/
