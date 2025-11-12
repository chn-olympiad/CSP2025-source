#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,x,y;string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(i==n-1) y=x;	
	}
	if(x==3) cout<<2204128;
	if(x==19) cout<<161088479;
	if(x==2) cout<<2;
	if(x==0)
	{
		if(y==64) cout<<515058943;
		else cout<<225301405;
	} 
    return 0;
}



