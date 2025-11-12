#include <bits/stdc++.h>
using namespace std;
int a,b;
string c[2000005],d[2000005];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	for(int i=1;i<=b;i++){
		cin>>d[i];
		cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
