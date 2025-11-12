#include<bits/stdc++.h>
using namespace std;
struct change
{
	string x;
	string y;
}a[10000];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s,z;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;	
	}for(int i=1;i<=m;i++){
		int cnt=0;
		cin>>s>>z;
		int l=s.size();
		for(int j=1;j<=m;j++){
			for(int k=j;k<=m;k++){
				string x=s.substr(j,k);
				for(int u=1;u<=n;u++){
					if(x==a[u].x) {
						cnt++;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
