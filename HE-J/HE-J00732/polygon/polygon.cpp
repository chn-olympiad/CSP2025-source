#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long a,b,c;
	cin>>a>>b>>c;
	if(a+b>c&&a+c>b&&c+b>a)  cout<<1;
	else  cout<<0;
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
