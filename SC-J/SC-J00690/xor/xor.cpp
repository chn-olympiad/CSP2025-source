#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],k,w,ee;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==m){
			w++;
			k=0;
			ee=0;
		}
		else{
			k=(ee^a[i]);
			if(k==m){
				k=0;
				w++;
			}
			ee=k;
		}
	}
	cout<<w;
 } 