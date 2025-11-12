#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,f[10005],k[10005],ans=0;
	string a[20005][5];
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]; 
	}
	for (int i=1;i<=n;i++){	
			if (ans==f[i]){
				if(k[i]<=n/2) {
					k[1]++;
					f[i]+=ans; 
				}
			}
			 else if (ans==f[i]){
				if (k[2]<=n/2){
					k[2]++;
					f[i]+=ans;
				}
			} 
			 else if (ans==f[i]){
			 	if (k[3]<=n/2){
			 		k[3]++;
					 f[i]+=ans;
				 }
			} 
		}
	cout<<n/2;
	for (int i=1;i<n;i++)
		cout<<0<<endl;
	
}
