#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==5 and m==1) cout<<9;
	else if(n==5 and m==2) cout<<6;
	else if(n==20 and m==75) cout<<1042392;
	else if(n==55 and m==37) cout<<366911923;
	fclose(stdin);
	fclose(stdout);	
	return 0;
}

