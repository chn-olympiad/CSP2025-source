#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long a,b,d,e;
	cin>>a>>b;
	long long c[a];
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	d=c[0];
	for(int i=1;i<b;i++){
		d=d&c[i];
	}
	e=c[b];
	for(int i=b+1;i<=a;i++){
		e=e&c[i];
	}
	cout<<max(d,e);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
