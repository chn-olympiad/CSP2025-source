#include <bits/stdc++.h>
using namespace std;

int f[550][550];
int v[550];
long long k=1;
int main()
{
	 int n,m;
	 cin>>n>>m;
	 string s;
	 int p=0;
	 cin>>s;
	 for(int i=0;i<n;i++)
	 {
	 	if(s[i]=='1')p++;
	 	else if(p<m)
		 {
		 	cout<<0;
		 	return 0;
		 }
	 	else{
			 	for(int i=1;i<=n;i++)
				{
		 			k*=i;
//		 			cout<<k<<"\n";
		 			k%=998244353;
				}
				cout<<k;
				return 0;
			}
	 }
} 
