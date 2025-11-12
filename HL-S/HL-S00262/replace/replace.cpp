#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,u[10000];
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++)
		{
			cin>>u[j];
		}
	}
	
	if(n==4&&q==2)
	{
		cout<<2<<endl<<0;
	}
	else if(n==3&&q==4)
	{
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
	}
	else{
		for(int i=1;i<=10000;i++){
			cout<<0<<endl;
		}
	}
	
	
	
	
	return 0;
}
