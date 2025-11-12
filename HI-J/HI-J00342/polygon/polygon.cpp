#include<bits/stdc++.h>
using namespace std;
int a,b,c,ma,s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a>>b>>c;
	ma=max(max(a,b),c);
	if(a+b+c>2*ma) s++;
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
