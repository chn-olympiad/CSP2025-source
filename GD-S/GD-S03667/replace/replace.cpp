#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,i=2;
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		cout<<n+i;
		i-=2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
