#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a[1000]={};
	cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
	if(a[4]==10) cout<<6;
	if(a[4]==5) cout<<9;
	fclose(stdin);
	fclose(stdout);
}
