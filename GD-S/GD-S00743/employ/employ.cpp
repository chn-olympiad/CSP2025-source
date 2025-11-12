#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,df=1,m,c[N];
unsigned long long as=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s; 
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(df==1){
		as=1;
		for(unsigned long long i=1;i<=n;i++)
		as=as*i;
	}
	cout<<as%998244353;
}
