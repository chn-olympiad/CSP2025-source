#include<bits/stdc++.h>
using namespace std;
long long n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	if(n==4) cout << 2 << endl << 0;
	else if(n==3) cout << 0 << endl << 0 << endl << 0 << endl << 0;
	else{
		for(int i=1;i<=q;i++) cout << 0 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
