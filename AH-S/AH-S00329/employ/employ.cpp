#include<bits/stdc++.h>
using namespace std;
bool qst[505];
int ca[505],lis[505];
const int M=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>ca[i];
	}int ans=1;
	for(int i=2;i<=n;i++){
		ans*=i;
		ans%=M;
	}cout<<ans;
	//Spc A [20]
}
