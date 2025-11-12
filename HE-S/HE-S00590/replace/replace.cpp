#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a[n+3],b[n+3],p[q+3];
	for(int i=1;i<=n;i++)//eryuaqnzu n
	{
		cin>>a[i]>>b[i];
		cout<<a[i]<<' '<<b[i]<<' '<<endl;
	}
	for(int j=1;j<=q;j++)//wenti q
	{
		cin>>p[j];
	}//shuru
	
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=n;j++)//eryuaqnzu n
		{
			if(p[i].find(a[i]))
			{
				//cout<<p[i].find(a[i]);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
