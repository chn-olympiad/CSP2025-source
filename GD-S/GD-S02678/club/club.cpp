#include <bits/stdc++.h>
using namespace std;
int t,n,a,b,c;
int suma=0,sumb=0,sumc=0;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a>>b>>c;
			suma+=a;
			sumb+=b;
			sumc+=c;
		} 
		cout<<max(suma,sumb,sumc)/2<<endl;
	}
	return 0;
} 
