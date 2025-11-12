#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500005],cnt = 0,b[500005][500005];
	cin>>n>>k;
	for(int i = 1;i<=n;i++)
		cin>>a[i];
	for(int i = 1;i<=n;i++)
		b[i][i] = a[i] xor a[i];
	for(int i = 1;i<=n;i++)
		for(int j = i+1;j<=n;j++)
			b[i][j] = b[i][j-1] xor a[j];
	for(int i = 1;i<=n;i++)
		for(int j = i+1;j<=n;j++)
			b[i][j] = a[i] xor a[j];
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)
			if(b[i][j] == k)
			cnt++;
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;		
}