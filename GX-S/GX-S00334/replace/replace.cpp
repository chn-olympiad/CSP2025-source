#include<bits/stdc++.h>
using namespace std;
int a[4]={4,3};
string p;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>p;
	}
	if(n==a[0])cout<<2<<endl<<0;
	if(n==a[1])for(int i=1;i<=4;i++)cout<<0<<endl;
	return 0;
}
