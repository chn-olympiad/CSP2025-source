#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
	}
	for(int i=1;i<=q;i++){
		string x,y;
		cin>>x>>y;
		cout<<(x.size()-n)*2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
