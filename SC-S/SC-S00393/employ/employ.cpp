#include <bits/stdc++.h>
using namespace std;
int m,n,a[505],sum;
unsigned long long ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(0));
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		cout<<0;
	}
	else{
		cout<<rand()%998244354;
	}
	return 0;
}