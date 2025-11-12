#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[500006];
	for(int i=1;i<n+1;i++){
		cin>>a[i];
	}
	int c=0;
	int t=0;
	int m[2][500006]={{0},{0}};
	for(int f=1;f<=n;f++){
		for(int s=n;s>=f;s--){
			c=0;
			for(int i=0;i<s-f+1;i++){
				c=int(c ^ a[f+i]);	
			}
			if(c==k){
				m[1][t]=f;
				m[2][t]=s;
				t++;
			}
		}
	}
	cout<<t;
	return 0;
}
