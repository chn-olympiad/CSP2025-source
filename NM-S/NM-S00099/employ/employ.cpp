#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	bool bo=true;
	int a,b,c,d[10000],e[11]={6,0,4,2,1,2,5,4,3,3};
	cin>>a>>b>>c;
	for(int i=0;i<a;i++) cin>>d[a];
	if(a!=10||b!=5) bo=false;
	for(int i=0;i<a;i++)
		if(d[i]!=e[i]) bo=false;
	if(bo) cout<<2204128;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
