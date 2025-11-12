#include<iostream>
using namespace std;
string s;
int n,v;
int z = 0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>v;cin>>s;
	for(int i=1;i<=n;i++){
		int q;cin>>q;
		if(q == 0)continue;
		z++;
	}
	//cout<<z<<endl;
	if(z<v){
		cout<<0;
		return 0;
	}
	long long fac = 1;
	for(int i=1;i<=n;i++)
	{
		fac *= i;
		fac %= 998244353; 
	}
	cout<<fac;
	return 0;
} 
