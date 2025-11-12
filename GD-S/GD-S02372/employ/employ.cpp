#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long  n1=1,m1=1;
long long c[113242];

string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)	cin>>c[i];
	for(int i=n-m+1;i<=n;i++)	m1*=i;
	//for(int i=1;i<=n;i++)	n1*=i;
	cout<<m1;
	return 0;
} 
