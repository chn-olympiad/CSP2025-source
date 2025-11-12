#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
int n,m;
string s;
int a[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	long long sum=0;
	for(int i=n;i>=n-m+1;i--){
		sum=sum*i%N;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
