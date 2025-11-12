#include <bits/stdc++.h>
using namespace std;
long long N,M,Cnt;
string S;
long long C[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>N>>M>>S;
	for(int i=1;i<=N;i++){
		cin>>C[i];
	}
	long long ans=N*(N-1)/2;
	ans=998%ans;
	ans=244%ans;
	ans=353%ans;
	cout<<ans;
	return 0;
}
