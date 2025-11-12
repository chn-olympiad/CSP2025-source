#include<bits/stdc++.h>
using namespace std;
long long int all=1;
int r[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ji=0;
	cin>>n>>m;
	string l;
	cin>>l;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		if(r[i]==0){
			ji++;
		}
	}
	int flag=0;
	all*=n-ji;
	for(int i=1;i<=n-1;i++){
		all*=i;
		cout<<all<<endl;
		all=all%998244353;
	}
	cout<<all;
	return 0;
}