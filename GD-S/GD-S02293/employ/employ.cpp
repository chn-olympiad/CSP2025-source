#include<bits/stdc++.h>
using namespace std;
const long long mod=998224353;
const int N=510;
string s1;
long long n,m,ans1=1,ans2=1,ans3=1,cnt=0;
long long q[N];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	getline(cin,s1);
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
	for(int i=1;i<=n;i++){
		ans1*=i;
	} 
	for(int i=1;i<=m;i++){
		ans2*=i;
	}
	for(int i=1;i<=(n-m);i++){
		ans3*=i;
	}
	cnt=(ans1%mod/(ans2%mod*ans3%mod));
	cout<<cnt;
	return 0;
	fclose(stdin);
	fclose(stdout);
	
}
