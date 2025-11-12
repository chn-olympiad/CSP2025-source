#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
int n,m;
const int mod=998244353;
string a;
int patience[maxn];
int step(int x){
	int res=1;
	for(int i=2;i<=x;i++){
		res=(res*(i%mod))%mod;
	}
	return res;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int count1=0;
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>patience[i];
		if(patience[i]>0) count1++;
	}
	cout<<step(count1);
		
	
	
	
	
	
	
	return 0;
}
