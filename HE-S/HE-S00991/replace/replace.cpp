#include<bits/stdc++.h>
using namespace std;
int n,q;
int a[200005][200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
