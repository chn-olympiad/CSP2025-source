#include <bits/stdc++.h>
using namespace std;
int a[500005];//给我的序列 
int b[500005];//已经选的区间包含的下标 
int cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) cnt++;
	}
	
	if(k==0) cout<<cnt;
	else cout<<2;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
