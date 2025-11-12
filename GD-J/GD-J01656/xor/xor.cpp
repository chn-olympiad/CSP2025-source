#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],c;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			c++;
		}
	}
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
