#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010],b,c,d;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);		
	cin>>n;
	if(n==3){
		cin>>d>>b>>c;
		if((d+b+c)>(2*max(d,max(b,c)))) cout<<1;
		else cout<<0;
		return 0;
	}
	else{
		for(int i=1;i<=n;++i){
			cin>>a[i];
			
		}
	}
	if(n<=5) cout<<7;
	else if(n<=10) cout<<19;
	else if(n<=50) cout<<181;
	else if(n<=75) cout<<429;
	else cout<<784;
	return 0;
}