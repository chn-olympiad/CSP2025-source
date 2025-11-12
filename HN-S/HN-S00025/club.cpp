#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	long long t,n,a,b,c,x=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		x=0;
		cin>>n;
		for(int k=1;k<=n;k++){
			cin>>a>>b>>c;
			x+=max(a,max(b,c));
		}
		cout<<x<<endl;
	}
	return 0;
}
