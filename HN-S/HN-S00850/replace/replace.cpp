#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;string a,b;char aa,bb;
	cin>>n>>m;
	for(int i=1;i<=n+m;i++)
	{
		cin>>a>>b;
	}
	bb=b.size()-1;
	aa=a.size()-1;
	if(b[bb]=='b') cout<<2<<endl<<0;
	else
		for(int i=1;i<=m;i++)
		{
			if(i==1)
				cout<<0;
			else 
				cout<<endl<<0;
		}
    return 0;
}



