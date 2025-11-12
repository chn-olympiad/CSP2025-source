#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<q;i++){
		cout<<abs(i*3-4*q);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
