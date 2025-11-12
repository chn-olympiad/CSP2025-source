#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	long long sum=1;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		if(t!=0){
			sum*=(t%N);
		}
	}
	cout<<sum%N;
	return 0;
}
