#include<iostream>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	if(n==1)	cout<<0;
	else	cout<<1;
	fclose(stdin);
	fclose(stdout);
}
