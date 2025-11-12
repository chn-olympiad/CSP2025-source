#include <bits/stdc++.h>
using namespace std;

int d[10000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int a,b,c; cin>>a>>b,c;
	for(int i=0;i<b;i++) cout<<0<<endl;
	for(int i=0;i<a;i++){
		cin>>d[i];
	}
	cout<<d[a-2]*d[a-1];
	return 0;
	fclose(stdin);
	fclose(stdout);
}
